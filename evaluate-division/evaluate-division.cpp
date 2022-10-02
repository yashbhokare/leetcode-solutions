class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> mapper;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i=0;i<n;i++){
            string s1 = equations[i][0];
            string s2=  equations[i][1];
            double div = values[i];
            mapper[s1].push_back({s2,div});
            mapper[s2].push_back({s1,1/div});
        }
        
        vector<double> result;
        unordered_set<string> visited;
        for(int i=0;i<queries.size();i++){
            string s1 = queries[i][0];
            string s2=  queries[i][1];
            // Case 1 where the string doesn't exist
            if(mapper.find(s1)==mapper.end() || mapper.find(s2)==mapper.end()){
                result.push_back(-1);
            }
            // Case 2 if both string are equal
            else if(s1==s2){
                result.push_back(1);
            }
            else {
                
                double ans = dfs(s1,s2,visited);
                result.push_back(ans);
            }
        }
        return result;
    }
    
    
    double dfs(string start,string end,unordered_set<string>& visited){
        if(visited.find(start)!=visited.end()) return -1;
        
        if(mapper.find(start)==mapper.end()) return -1;
        
        visited.insert(start);
        double result = -1;
        for(auto child:mapper[start]){
            string s2 = child.first;
            double v2 = child.second;
            if(s2==end){
                result = v2;
                break;
            }else {
                double val = dfs(s2,end,visited);
                if(val!=-1){
                    result = val*v2;
                    break;
                }
            }
        }
        
        visited.erase(start);
        return result;
    }
    
    
};