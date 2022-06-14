class Solution {
public:
    
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memo.resize(n,vector<int>(m,-1));
        int lcsCount = lcsWithRec(word1,word2,n-1,m-1);
        
        return n+m - 2*lcsCount;
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
};