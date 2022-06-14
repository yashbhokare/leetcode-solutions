class Solution {
public:
    
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int lcsCount=0;
        memo.resize(n,vector<int>(m,-1));
        // lcsCount = lcsWithRec(word1,word2,n-1,m-1);
        lcsCount = lcsWithDp(word1,word2,n,m);
        return n+m - 2*lcsCount;
        // Total size of both strings - 2 X size of common string
    }
    
    int lcsWithRec(string s1,string s2,int i,int j){
        if(i<0 || j<0) return 0;
        if(memo[i][j] > -1) return memo[i][j];
        if(s1[i]==s2[j]){
            memo[i][j] = 1 + lcsWithRec(s1,s2,i-1,j-1);
        }else {
            memo[i][j] = max(lcsWithRec(s1,s2,i-1,j),lcsWithRec(s1,s2,i,j-1));
        }
        return memo[i][j];
        
    }
    
    int lcsWithDp(string s1,string s2,int n,int m){
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int r=1;r<=n;r++){
            for(int c=1;c<=m;c++){
                if(s1[r-1]==s2[c-1]){
                    dp[r][c]=1+dp[r-1][c-1];
                }else {
                    dp[r][c] = max(dp[r-1][c],dp[r][c-1]);
                }
            }
        }
        return dp[n][m];
    }
};