struct Trie{
    int sum;
    unordered_map<char,Trie*> children;
};

class MapSum {
private: 
    Trie* root;
    unordered_map<string,int> mapper;
public:
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        int delta = val - mapper[key];
         mapper[key] = val;
        Trie* current = root;
        
        for(auto c:key){
            if(current->children.count(c)<=0){
                current->children[c] = new Trie();
            }
            current->children[c]->sum =  current->children[c]->sum + delta; 
            current =  current->children[c];
        }
    }
    
    int sum(string prefix) {
        Trie* current = root;
        for(auto c:prefix){
            if(current->children.count(c)<=0){
                return false;
            }
            current =  current->children[c];
        }
        return current->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */