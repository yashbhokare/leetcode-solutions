class Solution {
public:
    unordered_set<string> visited;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> mapper;
        vector<double> ans;
        for(int i=0;i<equations.size();i++){
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            mapper[dividend].insert({divisor,values[i]});
            mapper[divisor].insert({dividend,1/values[i]});
        }
        
        for(int i=0;i<queries.size();i++){
            string start = queries[i][0];
            string end = queries[i][1];
            if(mapper.find(start) == mapper.end() || mapper.find(end) == mapper.end()){
                ans.push_back(-1);
            }else if(start==end){
                ans.push_back(1);
            }else {
                double res = recursionResult(start,end,mapper);
                if(res==INT_MAX) ans.push_back(-1);
                else ans.push_back(res);
            }
        }
        return ans;
    }
    
    double recursionResult(string start,string end,unordered_map<string,unordered_map<string,double>>& mapper){
        unordered_map<string,double> childs = mapper[start];
        double result = INT_MAX;
        visited.insert(start);
        for(auto it=childs.begin();it!=childs.end();it++){
            if(it->first==end){
                result = min(result,it->second);
                break;
            }else {
                if(visited.find(it->first) == visited.end()){
                    double val = recursionResult(it->first,end,mapper);
                    if(val!=INT_MAX){
                         result = min(result,val*it->second);
                    }
                   
                    // cout<<it->first<<" "<<end<<":"<<result<<endl;
                }
                
            }
        }
        cout<<"Final:"<<result<<" Start:"<<start<<" End:"<<end<<endl;
        visited.erase(start);
        return result;
        
    }
};