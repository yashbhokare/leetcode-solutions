struct TrieNode{
    string val;
    bool is_end=false;
    unordered_map<char,TrieNode*> child;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto ch:word){
            if(curr->child.find(ch)==curr->child.end()){
                curr->child[ch] = new TrieNode();
            }
            curr=curr->child[ch];
        }
        curr->val = word;
        curr->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto ch:word){
            if(curr->child.find(ch)==curr->child.end()){
               return false;
            }
            curr=curr->child[ch];
        }
        return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto ch:prefix){
            if(curr->child.find(ch)==curr->child.end()){
               return false;
            }
            curr=curr->child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */