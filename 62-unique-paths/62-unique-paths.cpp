class Solution {
public:
    vector<vector<int>> matrix;
    int maxR=0;
    int maxC=0;
    int result = 0;
    int uniquePaths(int m, int n) {
        return uniquePathsUsingDp(m,n);
        // return uniquePathsUsingRec(m,n);
    }
    
    int uniquePathsUsingDp(int m,int n){
        matrix.resize(m,vector<int>(n,1));
        for(int r=1;r<m;r++){
            for(int c=1;c<n;c++){
                matrix[r][c] = matrix[r-1][c] + matrix[r][c-1];
            }
        }
        return matrix[m-1][n-1];
    }
    
    
    
    // TLE
    int uniquePathsUsingRec(int m, int n){
        maxR=m-1;
        maxC=n-1;
        matrix.resize(m,vector<int>(n,0));
        backtracking(0,0);
        return result;
    }
    
    void backtracking(int r,int c){
        if(r==maxR && c==maxC){
            result++;
        }
        
        // Already Visited
        if(matrix[r][c]!=0) return;
        
        //Mark as visited
        matrix[r][c]=1;
        
        if(r+1<=maxR && matrix[r+1][c]==0) backtracking(r+1,c);
        if(c+1<=maxC && matrix[r][c+1]==0) backtracking(r,c+1);
        
        // Backtrack and make it unvisted
        matrix[r][c]=0;
    }
};