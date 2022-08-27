class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        queue<int> q;
        vector<int> visited(s.size());
        
        q.push(0);
        while(!q.empty()){
            int start = q.front();
            q.pop();
            if(visited[start]) continue;
            
            for(int end=start+1;end<=s.size();end++){
                string newS = s.substr(start,end-start);
                if(wordSet.find(newS)!=wordSet.end()){
                    q.push(end);
                    if(end==s.size()) return true;
                }
            }
            visited[start] = 1;
        }
        
        return false;
    }
};