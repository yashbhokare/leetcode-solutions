class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // displayMatrix(board);
        return isValidSudokuCalculations(board);
    }
    
    bool isValidSudokuCalculations(vector<vector<char>>& board){
        
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> col(9,vector<bool>(9,false));
        vector<vector<bool>> box(9,vector<bool>(9,false));
        
        
        // for(int i =0;i<9;i++){
        //     for(int j =0;j<9;j++){
        //     row[i][j] = false;
        //     col[i][j] = false;
        //      box[i][j] = false ; 
        //     }
        // }
        
        for(int r =0;r<9;r++){
            for(int c =0;c<9;c++){
                if(board[r][c] == '.') continue;
                int val = board[r][c]-'1';
                    if(row[r][val]){
                        return false;
                    } else {
                        row[r][val] = true;
                    }
                    if(col[c][val]){
                        return false;
                    } else {
                        col[c][val] = true;
                    }
                    int boxPos = (r/3)*3 + c/3;
                    if(box[boxPos][val]){
                        return false;
                    } else {
                        box[boxPos][val] = true;
                    }
        
            }
        }
        return true;
    }
    
    
    
//     bool isValidSudokuCalculations(vector<vector<char>> board){
//          for(int i=0;i<board.size();i++){
//             for(int j=0; j<board[i].size();j++){
//                  // cout<<board[i][j]<<" ";
//             if(!isValidAcrossRow(board,i,j) || !isValidAcrossColumn(board,i,j) || !isValidInsideBox(board,i,j)){
//                     return false;
//                 }
//             }
//               // cout<<endl;
//          }
//         return true;
//     }
    
//     bool isValidAcrossRow(vector<vector<char>> board,int x,int y){
//         if(x==8) return true;
//         for(int val=x+1;val<board.size(); val++){
//             if(board[x][y]== board[val][y] && board[x][y] != '.'){
//                 return false;
//             }
//         }
//         return true;
//     }
    
//     bool isValidAcrossColumn(vector<vector<char>> board,int x,int y){
//         if(y==8) return true;
//         for(int val=y+1;val<board[x].size(); val++){
//             if(board[x][y] == board[x][val] && board[x][y] != '.' ){
//                 return false;
//             }
//         }
//         return true;
//     }
    
//     bool isValidInsideBox(vector<vector<char>> board,int x,int y){
//         int count = 0;
//         int startX = (x/3)*3;
//         int startY = (y/3)*3;
//         for(int i=startX;i<startX+3;i++){
//             for(int j=startY;j<startY+3;j++){
//                 if(board[i][j] == board[x][y] && board[x][y] != '.' ){
//                     count++;
//                 }
//                 if(count==2){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
    
    void displayMatrix(vector<vector<char>> board){
        for(int i=0;i<board.size();i++){
            for(int j=0; j<board[i].size();j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};