class Solution {
public:
    vector<int> dp;
    unordered_map<int, int> memo;
    int numDecodings(string s) {
        dp.resize(s.size()+1,0);
        return rec(s,0);
    }
    
    int rec(string s,int index){
         if (memo.find(index) != memo.end()) {
             cout<<index<<endl;
            return memo[index];
        }
        
        // if(dp[index]!=0) {
        //     cout<<index<<endl;
        //     return dp[index];
        // }
        
        if(index==s.size()) return 1;
        if(s[index]=='0') return 0;
        if(index==s.size()-1) return 1; 
        
        int res = rec(s,index+1);
        if(stoi(s.substr(index,2))<=26){
            res+=rec(s,index+2);
        }
        
        dp[index]=res;
        memo[index] = res;
        return res;
    }
};