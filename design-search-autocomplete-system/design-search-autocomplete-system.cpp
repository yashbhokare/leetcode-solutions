class Trie{
    struct Node{
        int size;
        bool isWord;
        unordered_map<char,Node*> child;
    };
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    
    static int compare(pair<string,int> a, pair<string,int> b){
        if(a.second==b.second) return a.first < b.first;
        return a.second > b.second;
    }
    
    void insert(string word,int val){
        Node* curr=root;
        for(auto ch:word){
            if(curr->child.count(ch)<=0) curr->child[ch]=new Node();
            // curr->child[ch]->size = curr->child[ch]->size+val;
            curr = curr->child[ch];
        }
        curr->size = curr->size + val;
        curr->isWord=true;
    }
    
    vector<string> findString(string searchWord){
        vector<string> result = {};
        Node* curr=root;
        for(auto ch:searchWord){
            if(curr->child.count(ch)<=0) return result;
            curr = curr->child[ch];
        }
        
        vector<pair<string,int>> ans = {};
        dfs(curr,searchWord,ans);
        
        sort(ans.begin(),ans.end(),compare);
        int size = ans.size();
        int minVal = min(size,3);
        for(int i=0;i<minVal;i++){
            result.push_back(ans[i].first);
        }
        return result;
    }
    
    void dfs(Node* curr,string prefix,vector<pair<string,int>>& result){
        // if(result.size()==3) return;
        if(curr->isWord) result.push_back({prefix,curr->size});
        
        for(auto it=curr->child.begin();it!=curr->child.end();it++){
            prefix.push_back(it->first);
            dfs(it->second,prefix,result);
            prefix.pop_back();
        }
    }
    
};


class AutocompleteSystem {
public:
    Trie* trie;
    string prefix ="";
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        for(int i=0;i<sentences.size();i++){
            trie->insert(sentences[i],times[i]);
        }
    }
    
    vector<string> input(char c) {
        
        if(c=='#'){
            trie->insert(prefix,1);
             prefix="";
            return {};
        }
        prefix+=c;
        
        
        // cout<<prefix<<endl;
        return trie->findString(prefix);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */