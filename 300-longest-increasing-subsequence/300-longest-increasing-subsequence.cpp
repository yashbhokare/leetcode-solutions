// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp(nums.size(),1);
//         int longest = 1;
//         for(int i=0;i<nums.size();i++){
//             int num = nums[i];
//             for(int j=0;j<i;j++){
//                 int curr_num = nums[j];
//                 if(curr_num<num){
//                     dp[i] = max(dp[i],dp[j]+1);
//                     longest = max(longest,dp[i]);
//                 }
//             }
//         }
//         return longest;
//     }
// };

// /https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

class Solution { // 8 ms, faster than 91.61%
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub.back() < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};