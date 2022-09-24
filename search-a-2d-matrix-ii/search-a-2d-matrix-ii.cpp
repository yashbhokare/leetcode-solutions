class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start our "pointer" in the bottom-left
        int row = matrix.size()-1;
        int col = 0;
        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] > target) {
                row--;
            } else if (matrix[row][col] < target) {
                col++;
            } else { // found it
                return true;
            }
        }

        return false;
    }
    

};