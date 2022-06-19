class Trie{
    struct Node{
        bool isWord;
        vector<Node*> child{vector<Node*>(26,NULL)};
    };
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* curr = root;
        for(auto ch:word){
            if(curr->child[ch-'a']==NULL) curr->child[ch-'a']= new Node();
            curr = curr->child[ch-'a'];
        }
        curr->isWord=true;
    }
    
    bool findWord(string searchWord){
        Node* curr = root;
        return dfs(curr,searchWord,0);
    }
    
    
    bool dfs(Node* curr,string searchWord,int index){
        if(index==searchWord.size()) return curr->isWord;
    
        char ch = searchWord[index];
        if(ch!='.' && curr->child[ch-'a']==NULL) return false;
        else if(ch!='.') return dfs(curr->child[ch-'a'],searchWord,index+1);
        else{
            bool res =false;
            bool contains=false;
            for(int i=0;i<26;i++){
                if(curr->child[i]!=0){
                    res = dfs(curr->child[i],searchWord,index+1);
                    if(res) return res;
                    contains = true;
                }
            }
            if(!contains) return false;
            return res;
        }
    }
    
};

class WordDictionary {
public:
    Trie* trie;
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->findWord(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */