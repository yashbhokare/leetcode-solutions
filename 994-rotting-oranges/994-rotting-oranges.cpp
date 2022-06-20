class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
    
    vector<vector<int>> dir = {
        {0,1},{0,-1},{1,0},{-1,0}
    };
    
    int bfs(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int rMax = grid.size();
        int cMax = grid[0].size();
        
        int totalFreshOranges = 0;
        for(int r=0;r<rMax;r++){
            for(int c=0;c<cMax;c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }else if(grid[r][c]==1){
                    totalFreshOranges++;
                }
            }
        }
        int result=0;
        if(totalFreshOranges==0) return result;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                // if(totalFreshOranges==0) return result;
                for(int i=0;i<4;i++){
                    int newR=r+dir[i][0];
                    int newC=c+dir[i][1];
                    if(newR>=0 && newR<rMax && newC>=0 && newC<cMax && grid[newR][newC]==1){
                        grid[newR][newC] = 2;
                        totalFreshOranges--;
                        q.push({newR,newC});
                    }
                }
            }
            result++;
        }
        if(totalFreshOranges==0) return result-1;
        return -1;
    }
    
};