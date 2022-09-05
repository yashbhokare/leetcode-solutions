class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        return bfs(grid);
    }
    
    vector<vector<int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}
    };
    
    int bfs(vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int startX = 0;
        int startY = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]=='*'){
                    startX=i;
                    startY=j;
                    break;
                }
        
        queue<pair<int,int>> q;
        q.push({startX,startY});
       
        int result = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                if(grid[x][y]=='#') return result;
                grid[x][y] ='X';
                q.pop();
                for(int i=0;i<4;i++){
                    int newX = x + dir[i][0];
                    int newY = y + dir[i][1];
                    if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]!='X'){
                        if(grid[newX][newY]=='#') return ++result;
                        q.push({newX,newY});
                        grid[newX][newY] ='X';
                    }
                }
            }
            result++;
        }
        return -1;
        
    }
};