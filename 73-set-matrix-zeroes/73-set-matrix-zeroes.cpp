class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isfirstCol = false;
        
        for(int r=0;r<matrix.size();r++){
            
            //Check if first column has 0 or not
            if(matrix[r][0]==0) isfirstCol=true;
            
            for(int c=1;c<matrix[0].size();c++){
                   if(matrix[r][c]==0){
                       matrix[r][0]=0;
                       matrix[0][c]=0;
                   }
            }
        }
        
        for(int r=1;r<matrix.size();r++){
            for(int c=1;c<matrix[0].size();c++){
                if(matrix[r][0] == 0 || matrix[0][c]==0) matrix[r][c]=0;
            }
        }
        
        // Check for first row
        if(matrix[0][0]==0){
            for(int c=0;c<matrix[0].size();c++) matrix[0][c]=0;
        }
        
        //Check for first column
        if(isfirstCol){
            for(int r=0;r<matrix.size();r++) matrix[r][0]=0;
        }
    }
};