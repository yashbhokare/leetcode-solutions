class Solution {
public:
    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount) {
        return rec(coins,amount);
    }
    
    int rec(vector<int>& coins, int rem){
        if(rem==0) return 0;
        if(rem<0) return -1;
        if(memo.find(rem)!=memo.end()) return memo[rem];
        
        int min=INT_MAX;
        for(auto& coin:coins){
            int res=rec(coins,rem-coin);
            if(res>=0 && res<min){
                min=1+res;
            }
        }
        memo[rem] = min == INT_MAX ? -1 : min;
        return memo[rem];
    }
};