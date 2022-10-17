struct TrieNode{
  unordered_map<char,TrieNode*> child;
  bool is_word = false;  
};

class WordDictionary {
    unordered_set<string> mapper;
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        mapper.insert(word);
        TrieNode* curr=root;
        for(auto ch:word){
            if(curr->child.find(ch)==curr->child.end()){
                curr->child[ch] = new TrieNode();
            }
            curr = curr->child[ch];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        
        if(mapper.find(word)!=mapper.end()) return true;
        
        TrieNode* curr=root;
        bool res = dfs(curr,0,word);
        if(res) mapper.insert(word);
        return res;
    }
    
    bool dfs(TrieNode* curr,int index,string word){
        if(index==word.size()){
            return curr->is_word;
        }
        if(word[index]!='.'){
             if(curr->child.find(word[index])==curr->child.end()){
                 return false;
             }
            return dfs(curr->child[word[index]],index+1,word);
        }else {
            for(auto it=curr->child.begin();it!=curr->child.end();it++){
                auto res = dfs(it->second,index+1,word);
                if(res) return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */