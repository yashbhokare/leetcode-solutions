class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int,vector<int>,greater<int>>> mapper;
        for(auto& item:items){
            mapper[item[0]].push(item[1]); 
            
            if(mapper[item[0]].size()>5){
                mapper[item[0]].pop();
            }
        }

        vector<vector<int>> res;
        for(auto it=mapper.begin();it!=mapper.end();it++){
            int id=it->first;
            int totalNums=it->second.size();
            int size=totalNums;
            int sum=0;
            while(size--){
                sum+=it->second.top();
                it->second.pop();
            }
            res.push_back({id,sum/totalNums});
        }
        sort(res.begin(),res.end());
        return res;
    }
};