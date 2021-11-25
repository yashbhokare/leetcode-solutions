class Solution {
public:
    unordered_map<int,int> cache;
    int fib(int n) {
        if(cache[n])  {
            // cout<<cache[n]<<" ";
            return cache[n];
            }
        if(n < 2 ) return n;
        int val = fib(n-1) + fib(n-2);
        cache[n] = val;
        return val;
    }
};