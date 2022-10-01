class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transpose(matrix);
        mirror(matrix);

        // for(int r=0;r<n/2;r++){
        //     for(int c=r;c<n-1-r;c++){
        //         int temp =matrix[n-c-1][r];
        //         matrix[n-1-c][r] = matrix[n-r-1][n-c-1];
        //         matrix[n-1-r][n-1-c] = matrix[c][n-1-r];
        //         matrix[c][n-1-r]= matrix[r][c];
        //         matrix[r][c] = temp;
        //     }
        // }
    }
    
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();
         for(int r=0;r<n;r++){
            for(int c=r+1;c<n;c++){
                swap(matrix[r][c],matrix[c][r]);
            }
         }
    }
    
    void mirror(vector<vector<int>>& matrix){
        int n = matrix.size();
         for(int r=0;r<n;r++){
            for(int c=0;c<n/2;c++){
                swap(matrix[r][c],matrix[r][n-c-1]);
            }
         }
    }
};