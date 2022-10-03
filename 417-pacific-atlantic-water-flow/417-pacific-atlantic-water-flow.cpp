class Solution {
public:
    int m,n;
    vector<vector<int>> dir ={
        {0,1},{1,0},{-1,0},{0,-1}
    };
    vector<vector<int>> result;
    vector<vector<int>> pacific;
    vector<vector<int>> atlantic;
    
    void display(vector<vector<int>>& heights){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<heights[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"*****************************"<<endl;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        pacific = heights;
        atlantic = heights;
        fill_pacific(pacific);
        fill_atlantic(atlantic);
        merged(pacific,atlantic);
        return result;
    }
    
    void merged(vector<vector<int>>& pacific,vector<vector<int>>& atlantic){
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(pacific[i][j]==-1 && atlantic[i][j]==-2){
                     result.push_back({i,j});
                 }
             }
        }
    }
    
    void fill_pacific(vector<vector<int>>& heights){
         for(int c=0;c<n;c++)
              dfs_pacific(heights,0,c);
         for(int r=1;r<m;r++)
              dfs_pacific(heights,r,0);
        // display(heights);
    }
    
    void fill_atlantic(vector<vector<int>>& heights){
         for(int c=0;c<n;c++)
              dfs_atlantic(heights,m-1,c);
         for(int r=0;r<m-1;r++)
              dfs_atlantic(heights,r,n-1);
        
        // display(heights);
    }
    
    void dfs_pacific(vector<vector<int>>& heights,int r,int c){
        if(heights[r][c]==-1) return;
        int height = heights[r][c];
        heights[r][c] = -1;
        for(int i=0;i<4;i++){
            int newR = r + dir[i][0];
            int newC = c + dir[i][1];
            if(newR>=0 && newR<m && newC>=0 && newC<n && heights[newR][newC]>=height){
                dfs_pacific(heights,newR,newC);
            }
        }
    }
    
    void dfs_atlantic(vector<vector<int>>& heights,int r,int c){
        // cout<<r<<" "<<c<<endl;
        if(heights[r][c]==-2) return;
        int height = heights[r][c];
        heights[r][c] = -2;
        for(int i=0;i<4;i++){
            int newR = r + dir[i][0];
            int newC = c + dir[i][1];
            if(newR>=0 && newR<m && newC>=0 && newC<n && (heights[newR][newC]>=height)){
                dfs_atlantic(heights,newR,newC);
            }
        }
    }
};