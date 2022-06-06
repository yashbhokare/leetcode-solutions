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
        //     if(moveRight && col+1<matrix[0].size() && target>=matrix[row][col+1]){
        //         col++;
        //     }else {
        //         return false;
        //     }                                                          
        }
        return false;
    }
};