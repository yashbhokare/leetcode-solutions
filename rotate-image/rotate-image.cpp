class Solution {
public:
    int nR,nC;
    void rotate(vector<vector<int>>& matrix) {
        nR = matrix.size();
        nC = matrix[0].size();
        transpose(matrix);
        mirror(matrix);
    }
    
    void transpose(vector<vector<int>>& matrix){
        for(int r=0;r<nR;r++){
            for(int c=r;c<nC;c++){
                swap(matrix[r][c],matrix[c][r]);
            }
        }
    }
    
    void mirror(vector<vector<int>>& matrix){
        for(int r=0;r<nR;r++){
            for(int c=0;c<nC/2;c++){
                swap(matrix[r][c],matrix[r][nC-1-c]);
            }
        }
    }
};