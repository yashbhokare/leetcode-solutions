class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        
        int reqSize = changed.size()/2;
        
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
            if(resultArray.size()>reqSize) return {};
        }
        if(resultArray.size()==reqSize){
            return resultArray;
        }else {
            return {};
        }
    }
};