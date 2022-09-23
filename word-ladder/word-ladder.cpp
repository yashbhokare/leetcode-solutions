class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> wordMap;
        unordered_set<string> visited;
        queue<string> q;
        
        for(auto word:wordList){
            for(int i=0;i<word.size();i++){
                string temp = word;
                int currCh = word[i];
                word[i] ='*';
                wordMap[word].push_back(temp);
                word[i] = currCh;
            }
        }
        
       
        q.push(beginWord);
        visited.insert(beginWord);
        
        int result = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr==endWord) return result+1;
                for(int i=0;i<curr.size();i++){
                    int currCh = curr[i];
                    curr[i] ='*';
                    if(wordMap.find(curr)!=wordMap.end()){
                        for(auto word:wordMap[curr]){
                            if(visited.find(word)==visited.end()){
                                q.push(word);
                                visited.insert(word);
                                if(word==endWord) return result+1;
                            }
                        }
                    }
                    curr[i] = currCh;
                }
            }
            cout<<endl;
            result++;
        }
        return 0;
    }
};