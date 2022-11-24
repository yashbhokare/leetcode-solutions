class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,1,i,j)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,string word,int index,int r,int c){
        if(index>=word.size()){
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        char tempCh = board[r][c];
        board[r][c] = '.';
        for(int i=0;i<4;i++){
            int newR = dir[i][0]+r;
            int newC = dir[i][1]+c;
            if(newR>=0 && newR<m && newC>=0 && newC<n && board[newR][newC]==word[index]){
                if(dfs(board,word,index+1,newR,newC)) return true;
            }
        }
        board[r][c] = tempCh;
        return false;
    }
};