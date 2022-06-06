class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int bfs(vector<vector<int>>& grid){
        int nr = grid.size();
        int nc = grid[0].size();
        queue<pair<int,int>> q;
        int freshCount = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }
        if(freshCount==0) return 0;
        if(q.size()==0) return -1;

        cout<<freshCount;
        cout<<q.size();
        int result = 0;
        while(!q.empty()){
            int qSize = q.size();
            cout<<q.size();
            while(qSize){
                if(freshCount==0) return result;
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<dir.size();i++){
                    int newR = r + dir[i][0];
                    int newC = c + dir[i][1];
                    
                    if(newR>=0 && newC>=0 && newR<nr && newC<nc && grid[newR][newC]==1){
                        grid[newR][newC] = 2;
                        q.push({newR,newC});
                        freshCount--;
                    }
                    if(freshCount==0) return result+1;
                }
                qSize--;
            }
            result++;
        }
        return -1;
     }
};