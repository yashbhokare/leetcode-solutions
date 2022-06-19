struct TrieNode{
    bool isWord;
    vector<TrieNode*> child{vector<TrieNode*>(26, NULL)};
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
     root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode* curr = root;
        for(auto ch:word){
            if(curr->child[ch-'a']==NULL) curr->child[ch-'a']= new TrieNode();
            curr = curr->child[ch-'a'];
        }
        curr->isWord=true;
    }
    
    vector<string> findString(string searchWord){
        vector<string> result;
         TrieNode* curr = root;
        for(auto ch:searchWord){
            if(curr->child[ch-'a']==NULL) return result;
            curr = curr->child[ch-'a'];
        }
        
        dfs(curr,searchWord,result);
        return result;
    }
    
    void dfs(TrieNode* curr,string prefix, vector<string>& result){
        if(result.size()==3) return;
        if(curr->isWord){
            result.push_back(prefix);
        }
        
        for(int i=0;i<26;i++){
            if(curr->child[i]!=0){
                prefix.push_back(i +'a');
                dfs(curr->child[i],prefix,result);
                prefix.pop_back();
            }
        }
        
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // return suggestedProductsBinaryApproach(products,searchWord);
        return suggestedProductsUsingTrie(products,searchWord);
    }
    
    vector<vector<string>> suggestedProductsBinaryApproach(vector<string>& products, string searchWord){
        
        // Sort Products
        sort(products.begin(),products.end());
        
        //Array to store the result
        vector<vector<string>> result;
        
        int start = 0;
        int bsStart =0;
        int end = products.size();
        
        string prefix = "";
        //Iterate through each char in searchWord
        for(auto ch:searchWord){
            
            prefix+=ch;
            // Find the index of first element with prefix char
            start = lower_bound(products.begin()+bsStart,products.end(),prefix)-products.begin();
            
            vector<string> ans;
            // cout<<prefix<<" ";
            for(int i=start;i<min(start+3,end);i++){
                // Compare the product string with prefix if it matches then continue else break
                if(products[i].compare(0,prefix.length(),prefix)!=0) break;
                
                ans.push_back(products[i]);
                // cout<<products[i]<<" ";
            }
            // cout<<endl;
            result.push_back(ans);
            bsStart= start;
        }
        return result;
    }
    
    vector<vector<string>> suggestedProductsUsingTrie(vector<string>& products, string searchWord){
        Trie* trie = new Trie();
        for(auto word:products){
            trie->insert(word);
        }
        
        vector<vector<string>> result;
        string prefix = "";
        for(auto ch:searchWord){
            prefix+=ch;
            result.push_back(trie->findString(prefix));
        }
        return result;
    }
    
};


































