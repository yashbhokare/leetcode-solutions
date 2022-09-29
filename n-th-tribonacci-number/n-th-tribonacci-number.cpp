class Solution {
public:
    unordered_map<int,int> memo;
    int tribonacci(int n) {
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        return dp(n);
    }
    
    int dp(int n){
        if(memo.find(n)!=memo.end()) return memo[n];
        memo[n] =dp(n-3) + dp(n-2) + dp(n-1);
        return memo[n];
    }
};