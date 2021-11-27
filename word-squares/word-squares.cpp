class Solution {
public:
    int n =0;
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> prefixSet;
   
    vector<vector<string>> wordSquares(vector<string>& words) {
    
    storePrefixStrings(words);
        
    for(string word:words){
        vector<string> wordArray;
        vector<string> result;
        wordArray.push_back(word);
        backTrack(1,wordArray,result);
        // if()
        // ans.push_back(result);
    }
    return ans;
    }
    
    void backTrack(int step,vector<string>& words,vector<string>& result){
        if(step==n){
            cout<<"Yessssssssss"<<result.size();
            // result = words;
            ans.push_back(words);
            return;
        }
        
        string prefix = "";
        for(string word:words){
            prefix+= word[step];
        }
        
        for(string newword:fetchPrefixWord(prefix)){
            words.push_back(newword);
            
            backTrack(step+1,words,result);
            
            words.pop_back();
        }
    }
    
    void storePrefixStrings(vector<string>& words){
        for(string word:words){
            n = word.size();
            for(int i=1;i<=word.size();i++){
                string v = word.substr(0,i);
                prefixSet[v].push_back(word);
            }
        }
    }
        
    vector<string> fetchPrefixWord(string s){
        if(prefixSet.find(s) == prefixSet.end()){
            return {};
        }else {
            return prefixSet[s];
        }
    }
};