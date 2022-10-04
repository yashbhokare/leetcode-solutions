struct TrieNode{
    bool is_word = false;
    string word = "";
    unordered_map<char,TrieNode*> child;
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string word){
        TrieNode* curr = root;
        for(auto ch:word){
            if(curr->child.find(ch)==curr->child.end()){
                curr->child[ch] = new TrieNode();
            }
            curr= curr->child[ch];
        }
        curr->is_word=true;
        curr->word = word;
    }
    
    string search(string word){
        TrieNode* curr = root;
        for(auto ch:word){
            if(curr->child.find(ch)==curr->child.end()){
              return word;
            }
            if(curr->child[ch]->is_word){
                return curr->child[ch]->word;
            }
            curr= curr->child[ch];
        }
        if(curr->is_word){
            return curr->word;
        }
        return word;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto word:dictionary){
            insert(word);
        }
        string result="";
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            result = result + " " + search(word);
        }
        // cout<<result;
        return result.substr(1);
    }
};