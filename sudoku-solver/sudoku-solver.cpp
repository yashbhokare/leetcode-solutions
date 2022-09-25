class Solution {
public:
    unordered_map<int,unordered_map<int,int>> row_map;
    unordered_map<int,unordered_map<int,int>> col_map;
    unordered_map<int,unordered_map<int,int>> box_map;
    bool result = false;
    
    void init(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int val = board[i][j]-'0';
                    int boxVal = (i/3)*3 + j/3;
                    row_map[i][val]++;
                    col_map[j][val]++;
                    box_map[boxVal][val]++;
                    
                }
            }
        }
    }
    
    void display(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        rec(board,0,0);
        // return result;
    }
    
    bool rec(vector<vector<char>>& board, int row,int col){
        // cout<<col<<
        // if(row==9) display(board);
        
        if(row==9){
            return true;
        }
        
        for(int c=col;c<=9;c++){
            if(board[row][c]!='.') continue;
            
            for(int num=1;num<=9;num++){
                int boxVal =(row/3)*3 + c/3; 
                if(row_map[row][num]==0 && col_map[c][num]==0 && box_map[boxVal][num]==0){
                    row_map[row][num]++;
                    col_map[c][num]++;
                    box_map[boxVal][num]++;
                    
                    board[row][c] = num+'0';
                    if(rec(board,row,c+1)) return true; 
                    
                    board[row][c] = '.';
                    row_map[row][num]--;
                    col_map[c][num]--;
                    box_map[boxVal][num]--;
                }
            }
            if(board[row][c]=='.') return false;
        }
        if(row_map[row].size()==9){
            if(rec(board,row+1,0)) return true;
        }
        return false;
    }
};