class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word(wordDict.begin(),wordDict.end());
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int start = q.front();
                q.pop();
                for(int end=start+1;end<=s.size();end++){
                    string new_word = s.substr(start,end-start);
                    if(word.find(new_word)!=word.end() && visited.find(end)==visited.end()){
                        q.push(end);
                        if(end==s.size()) return true;
                        visited.insert(end);
                    }
                }
            }
        }
        return false;
    }
};