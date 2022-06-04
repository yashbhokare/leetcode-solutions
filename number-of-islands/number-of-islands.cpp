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
                    bfs(grid,r,c);
                    res++;
                    // display(grid);
                }
            }
        }
        return res;
    }
    

    void bfs(vector<vector<char>>& grid,int row,int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        int rMax=grid.size()-1;
        int cMax=grid[0].size()-1;
        grid[row][col]='0';
        while(!q.empty()){
            int n= q.size();
            for(int i=0;i<n;i++){
                
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