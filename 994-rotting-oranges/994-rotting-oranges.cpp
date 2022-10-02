class Solution {
public:
    vector<vector<int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}  
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int total_fresh_oranges = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    total_fresh_oranges++;
                }
            }
        }
    // if(q.size()==0) return -1;
    
    if(total_fresh_oranges==0) return 0;
    int min = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int x = q.front().first;
            int y =  q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int newX = x + dir[d][0];
                int newY = y + dir[d][1];
                if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]==1){
                    grid[newX][newY]=2;
                    q.push({newX,newY});
                    total_fresh_oranges--;
                    if(total_fresh_oranges==0) return min+1;
                }
            }
        }
        min++;
    }
    return -1;
    }
};