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

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         for(int i=0;i<(n+1)/2;i++){
//             for(int j=0;j<n/2;j++){
//                 int temp = matrix[n-j-1][i];
//                 matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
//                 matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
//                 matrix[j][n-i-1] = matrix[i][j];
//                 matrix[i][j] = temp;
//             }
//         }
//     }
// };


    
//     void rotateCalculations(vector<vector<int>>& matrix){
//         // displayMatrix(matrix);
//         int matrixLength = matrix.size();
//         int count = 0;
//         int rowIndex = 0, columnIndex =0;
//         int n = matrix.size() - 1;
//         while(count< matrix.size()*matrix.size()){
//             int maxTraversal = matrixLength - 1;
//             if(maxTraversal == 0){
//                 break;
//             }
//             int index =0;
//             while(maxTraversal !=0){
//                 int temp = matrix[n-index-rowIndex][columnIndex];
//                 matrix[n-index-rowIndex][columnIndex] = matrix[n-rowIndex][n-columnIndex-index];
//                 matrix[n-rowIndex][n-columnIndex-index] = matrix[rowIndex+index][n-columnIndex];
//                 matrix[rowIndex+index][n-columnIndex] = matrix[rowIndex][columnIndex+index];
//                 matrix[rowIndex][columnIndex+index] = temp;
//                 maxTraversal--;
//                 index++;
//                 count = count + 4; //At each iteration 4 positions are getting updated
//                 // displayMatrix(matrix);
//                 // cout<<"Count:"<<count<<endl;
//             }
//             rowIndex++;
//             columnIndex++;
//             matrixLength = matrixLength -2;
//             // cout<<"MatrixLength:"<<matrixLength<<endl;
//         }
//     }
    
//     void displayMatrix(vector<vector<int>> matrix){
//         for(int i =0; i< matrix.size();i++){
//             for(int j=0;j<matrix.size();j++){
//                 cout<<matrix[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<"------------------"<<endl;
//     }