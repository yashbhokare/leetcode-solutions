class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int bottom=matrix.size()-1;
        int right=0;

        while(bottom>=0 && right<matrix[0].size()){
            while(right<matrix[0].size() && bottom>=0 && matrix[bottom][right] > target){
                bottom--;
            }
            if(bottom<0) return false;

            if(matrix[bottom][right]==target) return true;
           
            right++;
        }
        return false;
        
//         // start our "pointer" in the bottom-left
//         int row = matrix.length-1;
//         int col = 0;
//         while (row >= 0 && col < matrix[0].length) {
//             if (matrix[row][col] > target) {
//                 row--;
//             } else if (matrix[row][col] < target) {
//                 col++;
//             } else { // found it
//                 return true;
//             }
//         }

//         return false;
    }
};