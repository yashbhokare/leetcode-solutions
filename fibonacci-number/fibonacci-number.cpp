class Solution {
public:
    unordered_map<int,int> memo;
    int fib(int n) {
        if(memo.find(n)!=memo.end()){
            return memo[n];
        }
        if(n<2) {
            memo[n] = n;
            return n;
        };
        int sum = fib(n-1)+fib(n-2);
        
        memo[n]=sum;
        return sum;
        // return 0;
    }
};