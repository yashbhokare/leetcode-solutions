class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int pixel = image[sr][sc];
        if(pixel == newColor) return image;
        // vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0)); 
        dfs(image,sr,sc,newColor,pixel);
        return image;
    }
    
    void dfs(vector<vector<int>>& image,int r, int c, int newColor,int pixel){
        int nr=image.size(); 
        int nc = image[0].size();
        image[r][c] = newColor;
        if(r - 1 >=0 && image[r-1][c] == pixel) 
            dfs(image,r-1,c,newColor,pixel);
        if(r + 1 <nr && image[r+1][c] == pixel ) 
            dfs(image,r+1,c,newColor,pixel);
        if(c - 1 >=0 && image[r][c-1] == pixel) 
            dfs(image,r,c-1,newColor,pixel);
        if(c + 1 <nc && image[r][c+1] == pixel)
            dfs(image,r,c+1,newColor,pixel);
    }
};
