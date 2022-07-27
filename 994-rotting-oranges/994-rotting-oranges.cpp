class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
    
    int bfs(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int totalFreshOranges = 0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1) totalFreshOranges++;
                else if(grid[r][c]==2) q.push({r,c});
            }
        }
        
        if(totalFreshOranges==0) return 0;
        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            minutes++;
            while(size--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newR = r + dir[i][0];
                    int newC = c + dir[i][1];
                    
                    if(newR>=0 && newC>=0 && newR<grid.size() && newC<grid[0].size() && grid[newR][newC]==1){
                        totalFreshOranges--;
                        grid[newR][newC] = 2;
                        q.push({newR,newC});
                        if(totalFreshOranges==0) return minutes;
                    }
                }
                // if(totalFreshOranges==0) return minutes;
            }
        }
        if(totalFreshOranges==0) return minutes;
        return -1;
    }
};