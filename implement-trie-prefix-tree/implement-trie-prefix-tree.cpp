struct TrieNode{
    bool is_end = false;
    unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(auto ch:word){
            if(current->children.find(ch)==current->children.end()){
                current->children[ch] = new TrieNode();
            }
            current =  current->children[ch];
        }
        current->is_end = true;
    }
    
    bool search(string word) {
         TrieNode* current = root;
         for(auto ch:word){
             if(current->children.find(ch)==current->children.end()){
                 return false;
             }
             current =  current->children[ch];
         }
        if(current->is_end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
         for(auto ch:prefix){
             if(current->children.find(ch)==current->children.end()){
                 return false;
             }
             current =  current->children[ch];
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