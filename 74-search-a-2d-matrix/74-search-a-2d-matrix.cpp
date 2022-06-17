class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int moveRight = 0;
        int moveDown = 0;
        bool goDown=true;
        while(moveRight<n && moveDown<m){
            if(matrix[moveDown][moveRight]==target) return true;
            if(moveDown+1<m && goDown && target>=matrix[moveDown+1][moveRight]){
                moveDown++;
            }else{
                moveRight++;
                goDown=false;
            }
        }
        return false;
        
    }
};