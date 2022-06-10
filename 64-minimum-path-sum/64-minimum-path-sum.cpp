class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nr = grid.size()-1;
        int nc= grid[0].size()-1;
        
        // vector<vector<int>> dp(nr+1,vector<int>(nc+1,0));
        
        for(int r=nr;r>=0;r--){
            for(int c=nc;c>=0;c--){
                // Lowest row in the grid excluding the bottom last value
                if(r==nr && c!=nc){
                    grid[r][c] = grid[r][c]+grid[r][c+1];
                }else if(c==nc && r!=nr){
                // Right most column in the grid excluding the bottom last value
                    grid[r][c] = grid[r][c] + grid[r+1][c];
                }else if(c!=nc && r!=nr){
                    grid[r][c] = grid[r][c] + min(grid[r+1][c],grid[r][c+1]);
                }else {
                    grid[r][c] = grid[r][c];
                }
            }
        }
        return grid[0][0];
    }
};