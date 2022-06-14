class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,1},{0,-1},{1,0}};
    int rowMax,colMax,selectedColor;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        rowMax=image.size();
        colMax=image[0].size();
        selectedColor = image[sr][sc];
        dfs(image,sr,sc,color);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int color){
        // if(image[r][c]==color || image[r][c]!=0){
        //     return;
        // }
        image[r][c] = color;
        // cout<<r<<" "<<c<<endl;
        for(int i=0;i<4;i++){
            int newR = r+dir[i][0];
            int newC = c+dir[i][1];
            if(newR>=0 && newR<rowMax && newC>=0 && newC<colMax && image[newR][newC]==selectedColor){
                dfs(image,newR,newC,color);
            }
        }
    }
};