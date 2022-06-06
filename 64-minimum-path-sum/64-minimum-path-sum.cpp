class Solution {
public:
    int result=INT_MAX;
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if(i == grid.size() - 1 && j != grid[0].size() - 1)
                    dp[i][j] = grid[i][j] +  dp[i][j + 1];
                else if(j == grid[0].size() - 1 && i != grid.size() - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                else if(j != grid[0].size() - 1 && i != grid.size() - 1)
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                else
                    dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }
    
    void rec(vector<vector<int>>& grid,int r,int c,int total){
        int nr=grid.size();
        int nc=grid[0].size();
        if(r==nr-1 && c==nc-1){
            result=min(result,total);
            return;
        }
        int temp=grid[r][c];
        grid[r][c]=-1;
        if(r+1<nr && grid[r+1][c]!=-1){
            rec(grid,r+1,c,total+grid[r+1][c]);
        }
        if(c+1<nc && grid[r][c+1]!=-1){
            rec(grid,r,c+1,total+grid[r][c+1]);
        }
        grid[r][c]=temp;
    }
};