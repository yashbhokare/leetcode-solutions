class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        unordered_map<int,int> mapper;
        for(auto num:changed) mapper[num]++;
        sort(changed.begin(),changed.end());
        vector<int> resultArray;
        for(auto num:changed)
        {
            if(num==0 && mapper[num]<2) continue;
            
            if(mapper[num] && mapper[num*2]){
                
                mapper[num]--;
                mapper[num*2]--;

                resultArray.push_back(num);
            }
        }
        if(resultArray.size()==changed.size()/2){
            return resultArray;
        }else {
            return {};
        }
    }
};