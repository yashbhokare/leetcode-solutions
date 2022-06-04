class Solution {
public:
    vector<vector<string>> result;
    int size;
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<string> matrix;
        for(int i=0;i<n;i++){
            string row = "";
            for(int j=0;j<n;j++){
                row+=".";
            }
            matrix.push_back(row);
        }
        unordered_set<int> col;
        unordered_set<int> diag;
        unordered_set<int> anti_diag;
        backtrack(0,col,diag,anti_diag,matrix);
        return result;
    }
    void backtrack(int r,unordered_set<int>& col,unordered_set<int>& diag,unordered_set<int>& anti_diag,vector<string>& matrix){
        if(r==size){
            result.push_back(matrix);
            return;
        }
        
        for(int c=0;c<size;c++){
            if(col.find(c) != col.end() || diag.find(r-c) != diag.end() || anti_diag.find(r+c) != anti_diag.end()){
                continue;
            }
            matrix[r][c] = 'Q';
            col.insert(c);
            diag.insert(r-c);
            anti_diag.insert(r+c);
            
            backtrack(r+1,col,diag,anti_diag,matrix);
            
            // Backtrack
            matrix[r][c] = '.';
            col.erase(c);
            diag.erase(r-c);
            anti_diag.erase(r+c);
            
        }
    }
};