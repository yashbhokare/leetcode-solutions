class Solution {
public:
    unordered_map<int,int> memo;
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(memo[n]) return (memo[n]);
        memo[n] = climbStairs(n-1)+climbStairs(n-2);
        return memo[n];
    }
};