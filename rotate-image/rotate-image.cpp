class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        transpose(matrix,m,n);
        mirror(matrix,m,n);
    }
    
    void transpose(vector<vector<int>>& matrix,int m, int n){
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void mirror(vector<vector<int>>& matrix,int m, int n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};