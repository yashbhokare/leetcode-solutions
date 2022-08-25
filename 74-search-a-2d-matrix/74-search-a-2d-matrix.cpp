class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrixUsingBinarySearch(matrix,target);
    }
    
    bool searchMatrixSimple(vector<vector<int>>& matrix, int target) {
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
    
    bool searchMatrixUsingBinarySearch(vector<vector<int>>& matrix, int target){
        int maxR = matrix.size();
        int maxC = matrix[0].size();
        
        int low= 0;
        int high= maxR*maxC-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int value = matrix[mid/maxC][mid%maxC];
            if(target==value) return true;
            else if(target<value) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};