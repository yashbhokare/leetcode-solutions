class Solution {
public:
    unordered_map<int,int> memo;
    int rob(vector<int>& nums) {
        return dp(nums,nums.size()-1);
    }
    
    
    int dp(vector<int>& nums, int house){
        if(memo.find(house)!=memo.end()) return memo[house];
        
        if(house==0) return nums[0];
        if(house==1) return max(nums[1],nums[0]);
        
        memo[house] = max(dp(nums,house-2)+nums[house],dp(nums,house-1));
        return memo[house];
    }
    
    
};