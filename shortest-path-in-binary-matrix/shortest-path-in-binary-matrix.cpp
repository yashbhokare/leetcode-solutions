class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
    
    vector<vector<int>> dir = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,0},{-1,1}};

    int bfs(vector<vector<int>>& grid){
        int n = grid.size()-1;

        if(n==0 && grid[0][0]==0){
            return 1;
        }
        if(grid[0][0]==1){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});

        grid[0][0] = 1;
        int result = 1;
        while(!q.empty()){
            int qSize = q.size();
            while(qSize){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<dir.size();i++){
                    int newR = r + dir[i][0];
                    int newC = c + dir[i][1];

                    if(newR>=0 && newC>=0 && newR<=n && newC<=n && grid[newR][newC]==0){
                        if(newR==n && newC==n){
                            return result+1;
                        }
                        q.push({newR,newC});
                        grid[newR][newC] = 1;
                    }
                }
                qSize--;
            }
            result++;
        }
        return -1;
    }
};