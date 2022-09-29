class Solution {
public:
    unordered_map<int,int> num_mapper;
    unordered_map<int,int> cache;
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;
        for(int i=0;i<nums.size();i++){
            num_mapper[nums[i]]=num_mapper[nums[i]]+nums[i];
            maxNumber = max(nums[i],maxNumber);
        }
        return dp(maxNumber);
    }
    
    int dp(int n){
        if(cache.find(n)!=cache.end()) return cache[n];
        if(n==0) return 0;
        if(n==1) {
            if(num_mapper.find(1)==num_mapper.end()) return 0;
            else return num_mapper[1];
        }
        int gain = 0;
        if(num_mapper.find(n)!=num_mapper.end()){
            gain = num_mapper[n];
        }

        cache[n] = max(gain+dp(n-2),dp(n-1));
        return cache[n];
    }
};