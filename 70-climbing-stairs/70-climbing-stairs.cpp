class Solution {
public:
    unordered_map<int,int> memo;
    int climbStairs(int n) {
        return dp(n);
    }
    
    int dp(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        if(memo.find(n)!=memo.end()) return memo[n];
        
        memo[n] = dp(n-1) + dp(n-2);
        return memo[n];
        
    }
};