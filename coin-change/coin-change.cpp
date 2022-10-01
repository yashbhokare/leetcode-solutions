class Solution {
public:
    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount) {
        return rec(coins,amount);
    }
    
    int rec(vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }else if(amount<0){
            return -1;
        }
        
        if(memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        int ans = INT_MAX;
        for(auto coin:coins){
            int val = rec(coins,amount-coin);
            if(val>-1 && val<ans){
                ans = val+1;
            }
        }
        if(ans==INT_MAX){
            ans=-1;
        }
        memo[amount] = ans;
        return ans;

    }
};