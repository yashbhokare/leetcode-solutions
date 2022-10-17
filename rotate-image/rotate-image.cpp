class Solution {
public:
    int n;
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        transpose(matrix);
        mirror(matrix);
    }
    
    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void mirror(vector<vector<int>>& matrix){
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};