class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int maxX,maxY;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        maxX = image.size();
        maxY = image[0].size();
        dfs(sr,sc,image,color,image[sr][sc]);
        return image;
    }
    
    void dfs(int x,int y,vector<vector<int>>& image,int newColor, int oldColor){

        image[x][y]=newColor;
        for(int i=0;i<dir.size();i++){
            int newX = x+ dir[i][0];
            int newY = y + dir[i][1];
            if(newX>=0 && newX<maxX && newY>=0 && newY<maxY && image[newX][newY]==oldColor){
                dfs(newX,newY,image,newColor,oldColor);
            }
        }
    }
};