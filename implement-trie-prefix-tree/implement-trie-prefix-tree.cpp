
class TrieNode {
    public:
    bool is_word;
    vector<TrieNode*> children;
    
    TrieNode(){
        is_word = false;
        children.resize(26,NULL);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current =root;
        for(auto& c:word){
            if(current->children[c-'a']==NULL){
                current->children[c-'a'] = new TrieNode();
            }
            current = current->children[c-'a'];
        }
        current->is_word=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current =root;
        for(auto& c:word){
          if(current->children[c-'a']==NULL) return false;
            current = current->children[c-'a'];
        }
        return current->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* current =root;
        for(auto& c:prefix){
          if(current->children[c-'a']==NULL) return false;
            current = current->children[c-'a'];
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