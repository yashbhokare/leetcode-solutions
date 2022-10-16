struct TrieNode{
    bool is_word = false;
    string word = "";
    unordered_map<char,TrieNode*> child;
};

class Trie {
    TrieNode* root;
    unordered_set<string> result;
    vector<string> ans;
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
        dfs(curr,board,r,c);
    }
    
    vector<vector<int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}  
    };
    
    void dfs(TrieNode* parent, vector<vector<char>>& board,int r,int c){
        char ch = board[r][c];
        if(parent->child.find(ch)==parent->child.end()){
            return;
        }
        TrieNode* curr = parent->child[ch];
        
        if(curr->is_word){
            ans.push_back(curr->word);
            curr->is_word = false; // Important
        }

        board[r][c] = '0';
        for(int i=0;i<4;i++){
            int newR = r + dir[i][0];
            int newC = c + dir[i][1];
            if(newR>=0 && newR<board.size() && newC>=0 && newC<board[0].size() && curr->child.find(board[newR][newC])!=curr->child.end()){
                dfs(curr,board,newR,newC);
            }
        }
        board[r][c] = ch;
        
        // Best Case for Optimization
        // Once a match is found till leaf node then delete the node elements
        if(curr->child.size()==0){
            parent->child.erase(ch);
        }
        
    }
    
    vector<string> getResult(){
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