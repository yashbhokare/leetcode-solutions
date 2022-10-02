class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int longest = 1;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            for(int j=0;j<i;j++){
                int curr_num = nums[j];
                if(curr_num<num){
                    dp[i] = max(dp[i],dp[j]+1);
                    longest = max(longest,dp[i]);
                }
            }
        }
        return longest;
    }
};