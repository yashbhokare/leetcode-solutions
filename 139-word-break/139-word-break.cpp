// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
//         queue<int> q;
//         vector<int> visited(s.size());
        
//         q.push(0);
//         while(!q.empty()){
//             int start = q.front();
//             q.pop();
//             if(visited[start]) continue;
            
//             for(int end=start+1;end<=s.size();end++){
//                 string newS = s.substr(start,end-start);
//                 cout<<newS<<" ";
//                 if(wordSet.find(newS)!=wordSet.end()){
//                     q.push(end);
//                     if(end==s.size()) return true;
//                 }
//             }
//             // cout<<endl;
//             visited[start] = 1;
//         }
        
//         return false;
//     }
// };

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        // In the memo table, -1 stands for the state not yet reached,
        // 0 for false and 1 for true
        vector<int> memo(s.length(), -1);
        return wordBreakMemo(s, word_set, 0, memo);
    }

    bool wordBreakMemo(string& s, set<string>& word_set, int start, vector<int>& memo) {
        if (start == s.length()) {
            return true;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (word_set.find(s.substr(start, end - start)) != word_set.end() and
                wordBreakMemo(s, word_set, end, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
};