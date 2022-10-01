class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int start = q.front();
                q.pop();
                // if(visited.find(start)!=visited.end()) continue;
                
                for(int end =start+1;end<=s.size();end++){
                    string curr = s.substr(start,end-start);
                    // cout<<curr<<" ";
                    if(words.find(curr)!=words.end() && visited.find(end)==visited.end()){
                        cout<<curr<<" ";
                        visited.insert(end);
                        if(end==s.size()) return true;
                        q.push(end);
                    }
                }
            }
            cout<<endl;
        }
        return false;
        
    }
};