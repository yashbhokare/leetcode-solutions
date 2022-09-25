// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
        
//     }
// };

class Solution {
public:
    unordered_set<int> col_map;
    unordered_set<int> diag;
    unordered_set<int> anti_diag;
    vector<string> matrix;
    int N;
    int count=0;
    vector<vector<string>> result;
    
    void init(int n){
        N = n;
        for(int i=0;i<N;i++){
            string level = "";
            for(int j=0;j<N;j++){
                level.push_back('.');
            }
            matrix.push_back(level);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        init(n);
        // display();
        rec(0);
        
        return result;
    }
    
    void display(){
        for(int i=0;i<N;i++){
                cout<<matrix[i]<<endl;
            }
        cout<<"**********************\n";
    }
    
    void rec(int row){
        if(row==N){
            result.push_back(matrix);
            count++;
            return;
        }
        
        for(int col=0;col<N;col++){
            int diag_value = row-col;
            int anti_diag_value=row+col;
            if(
                diag.find(diag_value)==diag.end() && 
                anti_diag.find(anti_diag_value)==anti_diag.end() &&
                col_map.find(col)==col_map.end()
            ){
                diag.insert(diag_value);
                anti_diag.insert(anti_diag_value);
                col_map.insert(col);
                matrix[row][col]='Q';
                
                // Recursion call
                rec(row+1);
                
                // Backtrack
                diag.erase(diag_value);
                anti_diag.erase(anti_diag_value);
                col_map.erase(col);
                matrix[row][col]='.';
            }
           
        }
    }
};