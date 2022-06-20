class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mapper;
        int res=0;
        for(auto& num:nums){
            mapper[num]++;
        }
        
        for(auto it=mapper.begin();it!=mapper.end();it++){
            int key=it->first;
            int val=it->second;
            if(k>0 && mapper.find(key-k)!=mapper.end()){
                res++;
            }else if(k==0 & val>1){
                res++;
            }
        }
        return res;
    }
};