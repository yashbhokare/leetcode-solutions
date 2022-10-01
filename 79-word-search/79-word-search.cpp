class Solution {
public:
    int cMax,rMax;
    vector<vector<int>> dir = {
        {1,0},{0,1},{-1,0},{0,-1}
    };
    
    bool exist(vector<vector<char>>& board, string word) {
        rMax = board.size();
        cMax = board[0].size();
        
        for(int i=0;i<rMax;i++){
            for(int j=0;j<cMax;j++){
                if(word[0]==board[i][j]){
                    // cout<<i<<j<<endl;
                    if(rec(board,word,1,i,j)) return true;
                }
            }
        }
        return false;
    }
    
    unordered_set<char> visited;
    
    bool rec(vector<vector<char>>& board,string word,int index,int r,int c){
        if(board[r][c]=='.') return false;
        if(index==word.size()) return true;
        char temp = board[r][c];
        board[r][c]='.';
        for(int d=0;d<4;d++){
            int newR = dir[d][0] + r;
            int newC = dir[d][1] + c;
            if(newR>=0 && newR<rMax && newC>=0 && newC<cMax && board[newR][newC]==word[index]){
                // curr.push_back(board[newR][newC]);
                if(rec(board,word,index+1,newR,newC)) return true;
            }
        }
        board[r][c] = temp;
        return false;
    }
};