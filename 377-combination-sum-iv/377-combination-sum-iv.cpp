class Solution {
public:
    int result = 0;
    unordered_map<int,int> memo;
    int combinationSum4(vector<int>& nums, int target) {
        return rec(nums,target);
        // return result;
    }
    
    int rec(vector<int>& nums, int target){
        if(target==0){
            return 1;
        }
        if(target<0) return 0;
        
        if(memo.find(target)!=memo.end()) return memo[target];
        
        int ans = 0;
        for(auto num:nums){
            ans+=rec(nums,target-num);
        }
        memo[target]=ans;
        return  memo[target];
    }
};