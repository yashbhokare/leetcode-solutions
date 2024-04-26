class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<int>> col(9,vector<int>(9,0));
        vector<vector<int>> box(9,vector<int>(9,0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++) {
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'1';
                int boxIndex=(j/3)+((i/3)*3);
                if(row[i][num] || col[j][num] || box[boxIndex][num]) {
                    return false;
                }
                row[i][num]++;
                col[j][num]++;
                box[boxIndex][num]++;
            }
        }
        return true;
    }
};