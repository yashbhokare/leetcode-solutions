class Solution {
public:
    unordered_set<int> col_map;
    unordered_set<int> diag;
    unordered_set<int> anti_diag;
    vector<vector<int>> matrix;
    int N;
    int count=0;
    void init(int n){
        N = n;
        matrix.resize(n,vector<int>(n,0));
    }
    
    int totalNQueens(int n) {
        init(n);
        // display();
        rec(0);
        return count;
    }
    
    void display(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"**********************\n";
    }
    void rec(int row){
        // display();
        if(row==N){
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
                matrix[row][col]=1;
                
                // Recursion call
                rec(row+1);
                
                // Backtrack
                diag.erase(diag_value);
                anti_diag.erase(anti_diag_value);
                col_map.erase(col);
                matrix[row][col]=0;
            }
           
        }
    }
};