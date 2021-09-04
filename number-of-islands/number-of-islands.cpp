class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                     result+=markX(grid,i,j);
                    // display(grid);
                }
               
            }
        }
        return result;
    }
    
    int markX(vector<vector<char>>& grid,int posX,int posY){
        if(grid[posX][posY] == '1') grid[posX][posY] = 'X';
        else return 0;
        
        if(posX+1 <grid.size() &&  grid[posX+1][posY] == '1') markX(grid,posX+1,posY);
        if(posY+1 <grid[0].size() && grid[posX][posY+1] == '1') markX(grid,posX,posY+1);
        if(posY-1 >=0 && grid[posX][posY-1] == '1') markX(grid,posX,posY-1);
        if(posX -1 >=0 && grid[posX-1][posY] == '1') markX(grid,posX-1,posY);
        return 1;
    }
    
    void display(vector<vector<char>>& grid){
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<" ";
            }
             cout<<endl;
         }
         cout<<endl;
    }
};