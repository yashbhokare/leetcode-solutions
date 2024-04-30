class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]=='1'){
                    count++;
                    bfs(grid,r,c,m,n);
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>>& grid, int r, int c, int m, int n){
        queue<pair<int,int>> q;
        grid[r][c]='0';
        q.push({r,c});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row+1<m && grid[row+1][col]=='1'){
                    grid[row+1][col]='0';
                    q.push({row+1,col});
            }
            if(row-1>=0 && grid[row-1][col]=='1'){
                    grid[row-1][col]='0';
                    q.push({row-1,col});
            }            
            if(col+1<n && grid[row][col+1]=='1'){
                    grid[row][col+1]='0';
                    q.push({row,col+1});
            }            
            if(col-1>=0 && grid[row][col-1]=='1'){
                    grid[row][col-1]='0';
                    q.push({row,col-1});
            }
            
        }
    }
};