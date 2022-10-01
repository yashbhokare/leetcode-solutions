class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;
        for(int r=0;r<matrix.size();r++){
            
            if(matrix[r][0]==0) isCol=true;
            
            for(int c=1;c<matrix[0].size();c++){
                if(matrix[r][c]==0){
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        
        for(int r=1;r<matrix.size();r++){
            for(int c=1;c<matrix[0].size();c++){
                if(matrix[r][0]==0 || matrix[0][c]==0){
                    matrix[r][c] =0;
                }
            }
        }
        
        if(matrix[0][0]==0){
            for(int c=0;c<matrix[0].size();c++){
                matrix[0][c]=0;
            }
        }
        if(isCol){
            for(int r=0;r<matrix.size();r++){
                matrix[r][0]=0;
            }
        }
    }
};