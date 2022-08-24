class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transpose(matrix,n);
        mirror(matrix,n);
    }
    
    void transpose(vector<vector<int>>& matrix, int n){
        for(int r=0;r<n;r++){
            for(int c=r;c<n;c++){
                swap(matrix[r][c],matrix[c][r]);
            }
        }
    }
    
    void mirror(vector<vector<int>>& matrix, int n){
         for(int r=0;r<n;r++){
            for(int c=0;c<n/2;c++){
                swap(matrix[r][c],matrix[r][n-c-1]);
            }
        }
    }
};