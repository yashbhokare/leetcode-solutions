class Solution {
public:
    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount) {
        return rec(coins,amount);
    }
    
    int rec(vector<int>& coins,int remain){
        if(remain<0) return -1;
        if(remain==0) return 0;
        if(memo.find(remain)!=memo.end()) return memo[remain];
        
        int res = INT_MAX;
        for(auto coin:coins){
            int val = rec(coins,remain-coin);
            if(val>=0 && val<res){
                res = val + 1;
            }
        }
        if(res==INT_MAX) res=-1;
        memo[remain] = res;
        return memo[remain];
    }
};