class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> adjMap;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Creating the adj list for values
        for(int i=0;i<equations.size();i++){
            string s1=equations[i][0];
            string s2=equations[i][1];
            double val=values[i];
            
            adjMap[s1].push_back({s2,val});
            adjMap[s2].push_back({s1,1/val});
        }
        
        vector<double> result;
        
        for(int i=0;i<queries.size();i++){
            
            auto it1=adjMap.find(queries[i][0]);
            auto it2= adjMap.find(queries[i][1]);
            //Case 1 If any digit is not found add -1
            if(it1 == adjMap.end() || it2 == adjMap.end()){
                result.push_back(-1);
            }
            // Case 2 If both are equal and exist
            else if(queries[i][0]==queries[i][1]){
                result.push_back(1);
            }else {
                unordered_set<string> visited;
                double val = backtrack(queries[i][0],queries[i][1],visited);
                result.push_back(val);
            }
        }
        return result;
    }
    
    double backtrack(string start,string end,unordered_set<string>& visited){
        // String not found
        if(adjMap.find(start)==adjMap.end()){
           return -1; 
        }
        
        if(visited.find(start)!=visited.end()){
            return -1;
        }
        
        vector<pair<string,double>> children = adjMap[start];
        double res = -1;
        visited.insert(start);
        
        for(auto child:children){
            // cout<<child.first<<endl;
            if(child.first==end){
                return child.second;
            }else {
                
                res = max(res,backtrack(child.first,end,visited)*child.second);
            }
        }
        
        visited.erase(start);
        return res < 0 ? -1 : res;
        
    }
};