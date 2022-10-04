struct TrieNode{
    bool is_word = false;
    string word = "";
    unordered_map<char,TrieNode*> child;
};

class Trie {
    TrieNode* root;
    unordered_set<string> result;
    public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string s){
        TrieNode* curr=root;
        for(auto c:s){
            if(curr->child.find(c)==curr->child.end()){
                curr->child[c] = new TrieNode();
            }
            curr = curr->child[c];
        }
        curr->is_word = true;
        curr->word = s;
    }
    
    void search(vector<vector<char>>& board,int r,int c){
        TrieNode* curr=root;
        if(curr->child.find(board[r][c])==curr->child.end()){
            return;
        }
        curr = curr->child[board[r][c]];
        dfs(curr,board,r,c);
    }
    
    vector<vector<int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}  
    };
    
    void dfs(TrieNode* curr, vector<vector<char>>& board,int r,int c){
        char ch = board[r][c];
        if(curr->is_word){
            result.insert(curr->word);
        }

        board[r][c] = '0';
        for(int i=0;i<4;i++){
            int newR = r + dir[i][0];
            int newC = c + dir[i][1];
            if(newR>=0 && newR<board.size() && newC>=0 && newC<board[0].size() && curr->child.find(board[newR][newC])!=curr->child.end()){
                dfs(curr->child[board[newR][newC]],board,newR,newC);
            }
        }
        board[r][c] = ch;
        
    }
    
    vector<string> getResult(){
        vector<string> ans;
        for(auto it=result.begin();it!=result.end();it++){
            ans.push_back(*it);
        }
        cout<<result.size();
        return ans;
    }
    
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(auto word:words){
            t.insert(word);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                t.search(board,i,j);
            }
        }
        return t.getResult();
    }
};