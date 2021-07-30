class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        rotateCalculations(matrix);
    }
    
    void rotateCalculations(vector<vector<int>>& matrix){
        displayMatrix(matrix);
        int matrixLength = matrix.size();
        int count = 0;
        int rowIndex = 0, columnIndex =0;
        int n = matrix.size() - 1;
        while(count< matrix.size()*matrix.size()){
            int maxTraversal = matrixLength - 1;
            if(maxTraversal == 0){
                break;
            }
            int index =0;
            while(maxTraversal !=0){
                int temp = matrix[n-index-rowIndex][columnIndex];
                matrix[n-index-rowIndex][columnIndex] = matrix[n-rowIndex][n-columnIndex-index];
                matrix[n-rowIndex][n-columnIndex-index] = matrix[rowIndex+index][n-columnIndex];
                matrix[rowIndex+index][n-columnIndex] = matrix[rowIndex][columnIndex+index];
                matrix[rowIndex][columnIndex+index] = temp;
                maxTraversal--;
                index++;
                count = count + 4; //At each iteration 4 positions are getting updated
                displayMatrix(matrix);
                cout<<"Count:"<<count<<endl;
            }
            rowIndex++;
            columnIndex++;
            matrixLength = matrixLength -2;
            cout<<"MatrixLength:"<<matrixLength<<endl;
        }
    }
    
    void displayMatrix(vector<vector<int>> matrix){
        for(int i =0; i< matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"------------------"<<endl;
    }
};