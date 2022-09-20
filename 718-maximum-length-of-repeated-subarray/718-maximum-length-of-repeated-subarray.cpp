class Solution {
public:
    //Using longest common substring method
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxVal = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    maxVal = max(dp[i+1][j+1],maxVal);
                }
                
            }
        }
        return maxVal;
    }
};