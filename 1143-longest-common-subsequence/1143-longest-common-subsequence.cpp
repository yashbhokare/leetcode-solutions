class Solution {
public:
    string s1,s2;
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        s1=text1;
        s2=text2;
        memo.resize(1000,vector<int>(1000,-1));
        return dp(0,0);
    }
    
    int dp(int p1,int p2){
        
        if(p1>=s1.size() || p2>=s2.size()) return 0;
        if(memo[p1][p2]!=-1) return  memo[p1][p2];
        
        int ans=0;
        
        if(s1[p1]==s2[p2]){
            ans = 1 + dp(p1+1,p2+1);
        }else {
            ans = max(dp(p1,p2+1),dp(p1+1,p2));
        }
         memo[p1][p2] = ans;
        
        return ans;
    }
};