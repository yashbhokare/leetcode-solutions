class Solution {
public:
    
    vector<int> dp;
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return rec(n);
    }
    
    int rec(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        dp[n] = rec(n-1)+rec(n-2);
        return dp[n];
    }
};