class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mapper;
        for(auto n:nums){
            mapper[n]++;
        }
        
        for(auto it= mapper.begin();it!=mapper.end();it++){
                if(it->second > 0 ){
                    int freq = it->second;
                    int val = it->first;
                    for(int i=0;i<k;i++){
                        mapper[val+i] = mapper[val+i] - freq;
                        if(mapper[val+i] < 0) return false; 
                    }
                }    
        }
        
        return true;
    }
};