class Solution {
public:
    int m,n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>> cache(m,vector<int>(n,0));

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,dfs(i,j,cache,matrix));
            }
        }
        return ans;
    }
    
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    
    int dfs(int r,int c,vector<vector<int>>& cache,vector<vector<int>>& matrix){
        if(cache[r][c]) return cache[r][c];
        
        int ans=0;
        for(int i=0;i<4;i++){
            int newR = r + dir[i][0];
            int newC = c + dir[i][1];
            if(newR>=0 && newR<m && newC>=0 && newC<n && matrix[newR][newC]>matrix[r][c]){
                ans = max(ans,dfs(newR,newC,cache,matrix));
            }
        }
        cache[r][c] = ans + 1;// Include itself as well
        return cache[r][c];
    }
};