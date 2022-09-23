class Solution {
public:
    
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int maxX,maxY;
    int numIslands(vector<vector<char>>& grid) {
        maxX = grid.size();
        maxY = grid[0].size();
        int result=0;
        for(int i=0;i<maxX;i++){
            for(int j=0;j<maxY;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    result++;
                }
            }
        }
        return result;
    }
    
    
    void dfs(int x,int y,vector<vector<char>>& grid){
        grid[x][y]='0';
        for(int i=0;i<dir.size();i++){
            int newX = x+dir[i][0];
            int newY = y + dir[i][1];
            if(newX>=0 && newX<maxX && newY>=0 && newY<maxY && grid[newX][newY]=='1'){
                dfs(newX,newY,grid);
            }
        }
        
    }
};