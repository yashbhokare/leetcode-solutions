class Solution {
public:
    vector<vector<int>> dir={
        {0,1},{1,0},{-1,0},{0,-1}
    };
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]=='1'){
                    // bfs(grid,r,c);
                    dfs(grid,r,c);
                    res++;
                    // display(grid);
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid,int row,int col){
        int rMax=grid.size()-1;
        int cMax=grid[0].size()-1;
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            int newR=row+dir[i][0];
            int newC=col+dir[i][1];
            if(newR>=0 && newR<=rMax && newC>=0 && newC<=cMax && grid[newR][newC]=='1'){
                dfs(grid,newR,newC);
            }
        }
    }
    void bfs(vector<vector<char>>& grid,int row,int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        int rMax=grid.size()-1;
        int cMax=grid[0].size()-1;
        grid[row][col]='0';
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int newR=r+dir[j][0];
                int newC=c+dir[j][1];
                if(newR>=0 && newR<=rMax && newC>=0 && newC<=cMax && grid[newR][newC]=='1'){
                    q.push({newR,newC});
                    grid[newR][newC]='0';
                }
            }
        }
        
    }
    
    void display(vector<vector<char>>& grid){
    cout<<"----------------------------------";
    for(int r=0;r<grid.size();r++){
        for(int c=0;c<grid[0].size();c++){
            cout<<grid[r][c]<<" ";
            }
        cout<<endl;
        }
        
    }
};


// class Solution {
// private:
    
// void bfs(vector<vector<char>>& grid, int r, int c) {
//     int nr = grid.size();
//     int nc = grid[0].size();
//     queue<pair<int, int>> neighbors;
//     neighbors.push({r, c});
//     while (!neighbors.empty()) {
//         auto rc = neighbors.front();
//         neighbors.pop();
//         int row = rc.first, col = rc.second;
//         if (row - 1 >= 0 && grid[row-1][col] == '1') {
//           neighbors.push({row-1, col}); 
//           grid[row-1][col] = '0';
//         }
//         if (row + 1 < nr && grid[row+1][col] == '1') {
//           neighbors.push({row+1, col});
//           grid[row+1][col] = '0';
//         }
//         if (col - 1 >= 0 && grid[row][col-1] == '1') {
//           neighbors.push({row, col-1});
//           grid[row][col-1] = '0';
//         }
//         if (col + 1 < nc && grid[row][col+1] == '1') {
//           neighbors.push({row, col+1});
//           grid[row][col+1] = '0';
//         }
//     }
//  }
    
//  void dfs(vector<vector<char>>& grid, int r, int c) {
//     int nr = grid.size();
//     int nc = grid[0].size();

//     grid[r][c] = '0';
//     if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
//     if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
//     if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
//     if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
//   }

// public:
//   int numIslands(vector<vector<char>>& grid) {
//     int nr = grid.size();
//     if (!nr) return 0;
//     int nc = grid[0].size();

//     int num_islands = 0;
//     for (int r = 0; r < nr; ++r) {
//       for (int c = 0; c < nc; ++c) {
//         if (grid[r][c] == '1') {
//           ++num_islands;
//         //dfs(grid,r,c);
//           bfs(grid, r, c);
//         }
//       }
//     }

//     return num_islands;
//   }
// };