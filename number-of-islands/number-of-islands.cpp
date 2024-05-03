class Solution {
    vector<vector<int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}
    };
public:
    int rMax;
    int cMax;
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        rMax = grid.size();
        cMax = grid[0].size();
        for(int r=0;r<rMax;r++){
            for(int c=0;c<cMax;c++){
                if(grid[r][c]=='1'){
                    dfs(grid,r,c);
                    // bfs(grid,r,c);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid,int r,int c){
        grid[r][c]='0';
        for(int i=0;i<4;i++){
            int newRow=r+dir[i][0];
            int newCol=c+dir[i][1];
            if(newRow>=0 && newRow<rMax && newCol>=0 && newCol<cMax && grid[newRow][newCol]=='1'){
                dfs(grid,newRow,newCol);
            }
        }
    }
    
    void bfs(vector<vector<char>>& grid,int r,int c){
        queue<pair<int,int>> q;
        grid[r][c] = '0';
        q.push({r,c});
        while(!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newR = r + dir[i][0];
                int newC = c + dir[i][1];
                if(newR>=0 && newR<rMax && newC>=0 && newC<cMax && grid[newR][newC]=='1'){
                    grid[newR][newC] = '0';
                    q.push({newR,newC});

                }
            }
        }
    }
};