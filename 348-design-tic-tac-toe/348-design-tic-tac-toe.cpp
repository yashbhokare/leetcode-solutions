class TicTacToe {
public:
    int N;
    vector<int> rows;
    vector<int> cols;
    int diag;
    int anti_diag;
    
    TicTacToe(int n) {
        N = n;
        rows.resize(n,0);
        cols.resize(n,0);
        diag = 0;
        anti_diag=0;
    }
    
    int move(int row, int col, int player) {
        int currentPlayer = player==1 ? 1 : -1;
        rows[row]+=currentPlayer;
        cols[col]+=currentPlayer;
        
        if(row==col){
            diag+=currentPlayer;
        }
        if((row+col)==(N-1)){
            anti_diag+=currentPlayer;
        }
        
        if(abs(rows[row])==N || abs(cols[col])==N || abs(diag)==N || abs(anti_diag)==N){
            return player;
        }
        // cout<<player<<": "<<rows[row]<<" "<<cols[col]<<" "<<diag<<" "<<anti_diag<<endl;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */