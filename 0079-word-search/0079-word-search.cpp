class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    // vector<vector<char>> temp = board;
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
        // cout<<tempCh<<" ";
        board[r][c] = '.';
        for(int i=0;i<4;i++){
            int newR = dir[i][0]+r;
            int newC = dir[i][1]+c;
            // cout<<newR<<" "<<newC<<endl;
            if(newR>=0 && newR<m && newC>=0 && newC<n && board[newR][newC]==word[index]){
                index++;
                if(dfs(board,word,index,newR,newC)) return true;
                index--;
            }
        }
        board[r][c] = tempCh;
        return false;
    }
};