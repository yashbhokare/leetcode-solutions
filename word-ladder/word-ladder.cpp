class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> wordSet;
        unordered_set<string> visited;
         string newWord = "";
        for(string word:wordList){
            for(int i=0;i<word.size();i++){
                newWord = word.substr(0,i) + '*' + word.substr(i+1);
                wordSet[newWord].push_back(word);
                cout<<newWord<<" ";
            }
        }
        
        queue<string> q;
        cout<<endl<<beginWord;
        q.push(beginWord);
        visited.insert(beginWord);
        int result = 1;
        while(!q.empty()){
            int qSize = q.size();
            cout<<endl;
            for(int i=0;i<qSize;i++){
                string word = q.front();
                for(int i=0;i<word.size();i++){
                    newWord = word.substr(0,i) + '*' + word.substr(i+1);
                    auto it = wordSet.find(newWord);
                    if(it != wordSet.end()){
                        vector<string> wordValues = it->second;
                        for(string wordVal: wordValues){
                            if(visited.find(wordVal) == visited.end()){
                                cout<<wordVal<<" ";
                                if(wordVal==endWord){
                                    return result+1;
                                }
                                q.push(wordVal);
                                visited.insert(wordVal);
                            }
                        }                        
                    }
      
                }
                q.pop();
            }
            result++;
        }
        return 0;

    }
    
};