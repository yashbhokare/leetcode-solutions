class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0; 
        if(nums.size()==1) return nums[0]; 
        
        unordered_map<int,int> memo;
        int l1 = dp(nums,0,nums.size()-2,memo);
        memo = {};
        int l2 = dp(nums,1,nums.size()-1,memo);
        return max(l1,l2);
    }
    
    int dp(vector<int>& nums,int start,int i,unordered_map<int,int>& memo){

        if(i==start) return nums[start];
        if(i==start+1) return max(nums[start],nums[start+1]);
        if(memo.find(i)!=memo.end()) return memo[i];
        int amount = nums[i];
        memo[i] = max(dp(nums,start,i-2,memo)+amount,dp(nums,start,i-1,memo));

        
        
        return memo[i];
    }
};