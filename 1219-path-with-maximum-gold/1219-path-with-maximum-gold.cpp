class Solution {
public:
    vector<vector<int>> dir = {
        {1,0},{0,1},{-1,0},{0,-1}
    };
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]!=0){
                    result=max(result,dfs(grid,r,c));
                }
            }
        }
        return result;
    }
    
    int dfs(vector<vector<int>>& grid,int r,int c){
        int nr=grid.size();
        int nc=grid[0].size();
        
        int temp=grid[r][c];
        // Mark as Visited
        grid[r][c]=0;
        
        int maximum=0;
        for(auto& d:dir){
            int newR= d[0]+r;
            int newC = d[1]+c;
            if(newR>=0 && newC>=0 && newR<nr && newC<nc && grid[newR][newC]!=0){
                maximum= max(maximum,dfs(grid,newR,newC));
            }
        }
        // Backtrack to mark it not visited
        grid[r][c]=temp;
        return maximum+temp;
    }
};