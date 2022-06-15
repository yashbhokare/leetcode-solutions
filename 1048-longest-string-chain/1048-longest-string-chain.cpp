class Solution {
public:
    unordered_map<string,int> memo;
    unordered_set<string> wordList;
    int longestStrChain(vector<string>& words) {
        
        for(auto word:words){
            wordList.insert(word);
        }
        
        int result=1;
        for(auto word:words){
            result = max(result, dfs(word));
        }
        return result;
    }
    
    int dfs(string word){
        if(memo.find(word)!=memo.end()){
            return memo[word];
        }
        
        int maxLen=1;
        
        for(int i=0;i<word.size();i++){
            string newWord = word.substr(0,i) + word.substr(i+1);
            if(wordList.find(newWord)!=wordList.end()){
                int val = 1 + dfs(newWord);
                maxLen = max(maxLen,val);
            }
        }
        
        memo[word]=maxLen;
        return maxLen;
    }
};