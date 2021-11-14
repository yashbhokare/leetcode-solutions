class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> memo;
        unordered_set<string> wordList;
        for(int i =0;i<words.size();i++){
            wordList.insert(words[i]);
        }
        
        int maxLen = 0;
        for(int i=0;i<words.size();i++){
            maxLen = max(maxLen,dfs(words[i],wordList,memo));
        }
        return maxLen;
    }
    
    int dfs(string word,unordered_set<string>& wordList,unordered_map<string,int>& memo){
        
        if(memo.find(word)!=memo.end()){
            return memo[word];
        }
        
        int maxLen = 1;
        
        for(int i=0;i<word.size();i++){
            string newWord = word.substr(0,i)+word.substr(i+1);
            if(wordList.find(newWord) != wordList.end()){
                int currentLength = 1 + dfs(newWord,wordList,memo);
                maxLen = max(maxLen,currentLength);
            }
        }
        
        memo[word] = maxLen;
        
        return maxLen;
    }
};