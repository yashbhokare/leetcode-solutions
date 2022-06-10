class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nr = grid.size()-1;
        int nc= grid[0].size()-1;
        
        vector<vector<int>> dp(nr+1,vector<int>(nc+1,0));
        
        for(int r=nr;r>=0;r--){
            for(int c=nc;c>=0;c--){
                // Lowest row in the grid excluding the bottom last value
                if(r==nr && c!=nc){
                    dp[r][c] = grid[r][c]+dp[r][c+1];
                }else if(c==nc && r!=nr){
                // Right most column in the grid excluding the bottom last value
                    dp[r][c] = grid[r][c] + dp[r+1][c];
                }else if(c!=nc && r!=nr){
                    dp[r][c] = grid[r][c] + min(dp[r+1][c],dp[r][c+1]);
                }else {
                    dp[r][c] = grid[r][c];
                }
            }
        }
        return dp[0][0];
    }
};