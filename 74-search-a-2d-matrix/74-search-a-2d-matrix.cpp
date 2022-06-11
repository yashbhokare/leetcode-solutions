class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0,col=0;
        bool moveDown=true;
        bool moveRight=false;
        while(row<matrix.size() && col<matrix[0].size()){
            if(target==matrix[row][col]) return true;
            if(moveDown && row+1<matrix.size() && target>=matrix[row+1][col]){
                row++;
            }else {
                moveDown=false;
                moveRight=true;
                col++;
            }                                                       
        }
        return false;
    }
};

// class Solution {
//   public:
//   bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size();
//     if (m == 0)
//         return false;

//     int n = matrix[0].size();
//     // binary search
//     int left = 0, right = m * n - 1;
//     int pivotIdx, pivotElement;
//     while (left <= right) {
//       pivotIdx = (left + right) / 2;
//       pivotElement = matrix[pivotIdx / n][pivotIdx % n];
//       if (target == pivotElement)
//           return true;
//       else {
//         if (target < pivotElement)
//             right = pivotIdx - 1;
//         else
//             left = pivotIdx + 1;
//       }
//     }
//     return false;
//   }
// };