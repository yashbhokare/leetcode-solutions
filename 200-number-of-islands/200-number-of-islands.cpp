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
                    count++;
                }
            }
        }
        return count;
    }
    
    
    void dfs(vector<vector<char>>& grid,int r,int c){
        grid[r][c]='0';
        
        for(int i=0;i<4;i++){
            int newR = r + dir[i][0];
            int newC = c + dir[i][1];
            if(newR>=0 && newR<rMax && newC>=0 && newC<cMax && grid[newR][newC]=='1'){
                dfs(grid,newR,newC);
            }
        }
    }
};