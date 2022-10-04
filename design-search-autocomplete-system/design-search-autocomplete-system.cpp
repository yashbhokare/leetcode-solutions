struct TrieNode{
    string word="";
    bool is_word=false;
    unordered_map<char,TrieNode*> child;
};

class Trie {
    public:
    TrieNode* root;
    TrieNode* new_curr;
    string new_word = "";
    bool not_found = false;
    unordered_map<string,int> word_mapper;
    
    Trie(){
        root = new TrieNode();
        new_curr = root;
    }
    
    void insert(string word){
        TrieNode* curr = root;
        for(auto ch:word){
            if(curr->child.find(ch)==curr->child.end()){
                curr->child[ch] = new TrieNode();
            }
            curr = curr->child[ch];
        }
        curr->word=word;
        curr->is_word = true;
    }
    
    void addKey(string s,int val){
        word_mapper[s]+=val;
        insert(s);
    }
    
    void newSearch(){
        new_curr = root;
        new_word = "";
        not_found = false;
    }
    
    static int comparator(pair<int,string> &a,pair<int,string> &b){
        if(a.first==b.first){
            return a.second < b.second;
        }else {
            return a.first > b.first;
        }
    }
    vector<string> search(char c){
        new_word.push_back(c);
        
        TrieNode* curr = new_curr;
        if(curr->child.find(c)==curr->child.end() || not_found){
            not_found = true;
            return {};    
        }
        curr = curr->child[c];
        new_curr = curr;
        vector<pair<int,string>> values;
        
        dfs(curr,values);
        
        sort(values.begin(),values.end(),comparator);
        
        int size = values.size();
        int maxVal = min(size,3);
        vector<string> ans;
        for(int i=0;i<maxVal;i++){
            ans.push_back(values[i].second);
        }
        return ans;
        
    }
    
    void addCurrentWord(){
        addKey(new_word,1);
    }
    
    void dfs(TrieNode* curr,vector<pair<int,string>>& values){
        if(curr->is_word){
            values.push_back({word_mapper[curr->word],curr->word});
        }
        if(curr->child.size()==0){
            return;
        }
        
        for(auto it=curr->child.begin();it!=curr->child.end();it++){
            dfs(it->second,values);
        }
        
    }
    
};

class AutocompleteSystem {
public:
    Trie t;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i=0;i<sentences.size();i++){
            t.addKey(sentences[i],times[i]);
        }
        
    }
    
    vector<string> input(char c) {
        // return {};
        if(c=='#'){
            t.addCurrentWord();
            t.newSearch();
            return {};
        }else {
            return t.search(c);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */