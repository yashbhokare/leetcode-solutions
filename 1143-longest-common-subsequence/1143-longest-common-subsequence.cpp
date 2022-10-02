class Solution {
public:
    string s1,s2;
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        return dpUsingMatrix(text1,text2);
        
        s1=text1;
        s2=text2;
        // Make the memo big enough to hold the cases where the pointers
        // go over the edges of the strings.
        memo.resize(1000,vector<int>(1000,-1));
        // We need to initialise the memo array to -1's so that we know
        // whether or not a value has been filled in
        return dp(0,0);
    }
    
    int dp(int p1,int p2){
        
        if(p1>=s1.size() || p2>=s2.size()) return 0;
        
        // Check whether or not we've already solved this subproblem.
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
    
    
    int dpUsingMatrix(string text1, string text2){
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,(vector<int>(n+1,0)));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<j<<endl;
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }else {
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
