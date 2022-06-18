struct Trie{
    bool isWord;
    unordered_map<char,Trie*> child;
};

class Solution {
private:
    Trie* root = new Trie();
public:
    
    void insertWords(string word){
        Trie* current = root;
        for(auto c:word){
            if(current->child.count(c)<=0) current->child[c]=new Trie();
            current = current->child[c];
        }
        current->isWord=true;
    }
    
    string prefix(string word){
        string result = "";
        Trie* current = root;
         for(auto c:word){
             if(current->child.count(c)<=0) return word;
             result = result + c;
             if(current->child[c]->isWord) return result;
             current = current->child[c];
         }
        return result;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto word:dictionary) {
            insertWords(word);
        }
        
        stringstream ss(sentence);
        string word;
        string result = "";
        while(ss>>word){
            result = result + " "+prefix(word);
        }
        return result.substr(1);
    }
};