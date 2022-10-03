class Solution {
public:
    vector<vector<int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}
    };
    int maxX,maxY;
    int numIslands(vector<vector<char>>& grid) {
        int result=0;
        maxX=grid.size();
        maxY = grid[0].size();
        for(int i=0;i<maxX;i++){
            for(int j=0;j<maxY;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    result++;
                }
            }
        }
        return result;
    }
    
    void dfs(vector<vector<char>>& grid,int r,int c){
        grid[r][c]='0';
        for(int d=0;d<4;d++){
            int newX = r+dir[d][0];
            int newY = c+dir[d][1];
            if(newX>=0 && newX<maxX && newY>=0 && newY<maxY && grid[newX][newY]=='1'){
                dfs(grid,newX,newY);
            }
        }
    }
};