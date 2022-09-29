class Solution {
public:
    unordered_map<string,vector<string>> mapper;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto word:wordList){
            string curr_word = word;
            for(int i=0;i<word.size();i++){
                char temp = word[i];
                word[i]='*';
                mapper[word].push_back(curr_word);
                word[i] = temp;
            }
        }
        return bfs(beginWord,endWord);
        // return {{}};
    }
    
    int bfs(string beginWord, string endWord){
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
         cout<<beginWord<<endl;
        int result = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string word = q.front();
                if(word==endWord){
                    return result+1;
                }
                q.pop();
                for(int i=0;i<word.size();i++){
                    char temp = word[i];
                    word[i]='*';
                    for(auto list_word:mapper[word]){
                        if(visited.find(list_word)==visited.end()){
                            cout<<list_word<<" ";
                            q.push(list_word);
                            visited.insert(list_word);
                            if(list_word==endWord){
                                return result+1;
                            }
                        }
                    }
                    word[i] = temp;
                }
            }
            cout<<endl;
            result++;
        }
        return 0;
    }
};