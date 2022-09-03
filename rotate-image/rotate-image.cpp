// class Solution {
// public:
//     int nR,nC;
//     void rotate(vector<vector<int>>& matrix) {
//         nR = matrix.size();
//         nC = matrix[0].size();
//         transpose(matrix);
//         mirror(matrix);
//     }
    
//     void transpose(vector<vector<int>>& matrix){
//         for(int r=0;r<nR;r++){
//             for(int c=r;c<nC;c++){
//                 swap(matrix[r][c],matrix[c][r]);
//             }
//         }
//     }
    
//     void mirror(vector<vector<int>>& matrix){
//         for(int r=0;r<nR;r++){
//             for(int c=0;c<nC/2;c++){
//                 swap(matrix[r][c],matrix[r][nC-1-c]);
//             }
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<(n+1)/2;j++){
                int temp = matrix[n-i-1][j];
                matrix[n-i-1][j] = matrix[n-j-1][n-i-1];
                matrix[n-j-1][n-i-1] = matrix[i][n-j-1];
                matrix[i][n-j-1] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};


// class Solution {
// public:
    
//     void rotate(vector<vector<int>>& matrix) 
//     {
//         int n = matrix.size();
        
//         for(int row = 0; row < n/2; row++)
//             for(int col = row; col < n - row - 1; col++)
//             {                
//                 swap(matrix[row][col], matrix[col][n - 1 - row]);
//                 swap(matrix[row][col], matrix[n - 1 - row][n - 1 - col]);
//                 swap(matrix[row][col], matrix[n - 1 - col][row]);
//             }
//     }
// };