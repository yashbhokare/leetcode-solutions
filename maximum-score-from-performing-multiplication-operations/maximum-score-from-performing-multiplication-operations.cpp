class Solution {
public:
//     int memo[1000][1000];
//     int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//         // memo.resize(multipliers.size(),vector<int>(multipliers.size(),0));
//         return dp(nums,multipliers,0,0);
//     }
    
//     int dp(vector<int>& nums,vector<int>& multipliers,int left,int index){
//         if(index>=multipliers.size()){
//             return 0;
//         }
        
//         // int right=
//         int multi = multipliers[index];
//         int right = (nums.size()-1)-(index-left);
//         if(memo[left][index]==0){
//             memo[left][index] = max(nums[left]*multi+dp(nums,multipliers,left+1,index+1),
//                                     nums[right]*multi+dp(nums,multipliers,left,index+1));
//         }
//         return memo[left][index];
        
        
//     }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        
        for (int i = m - 1; i >= 0; i--) {
            for (int left = i; left >= 0; left--) {
                int mult = multipliers[i];
                int right = n - 1 - (i - left);
                dp[i][left] = max(mult * nums[left] + dp[i + 1][left + 1], 
                                       mult * nums[right] + dp[i + 1][left]);
            }
        }
        
        return dp[0][0];
    }
};