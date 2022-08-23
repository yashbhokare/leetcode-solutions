class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<int>> col(9,vector<int>(9,0));
        vector<vector<int>> box(9,vector<int>(9,0));
        
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') continue;
                int val = board[r][c]-'1';
                int boxCal =((r/3)*3)+c/3;
                // cout<<val;
                if(row[r][val]++) return false;
                if(col[c][val]++) return false;
                if(box[boxCal][val]++) return false;
            }
        }
        return true;
    }
};