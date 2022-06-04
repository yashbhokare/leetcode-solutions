class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int bottom=matrix.size()-1;
        int right=0;

        while(bottom>=0 && right<matrix[0].size()){
            while(right<matrix[0].size() && bottom>=0 && matrix[bottom][right] > target){
                // cout<<matrix[bottom][right]<<" ";
                bottom--;
            }
            
            if(bottom<0) return false;
            // cout<<matrix[bottom][right]<<" ";
            if(matrix[bottom][right]==target) return true;
            // if(matrix[bottom][right] > target) return false;
            right++;
        }
        return false;
    }
};