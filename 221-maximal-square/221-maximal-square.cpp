class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int nr=matrix.size();
        int nc= matrix[0].size();
        int res= 0;
        for(int r=1;r<=nr;r++){
            for(int c=1;c<=nc;c++){
                if(matrix[r-1][c-1]=='1'){
                    dp[r][c] = min(min(dp[r-1][c],dp[r-1][c-1]),dp[r][c-1]) + 1;
                    res = max(res,dp[r][c]);
                }
            }
        }
        return res*res;
    }
};