class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size()+1,vector<int>(triangle.size()+1,0));
        int rowN=triangle.size()-1;
        for(int i=rowN;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[0][0];
    }
};