class Solution {
public:
    int ans = 0;
    unordered_map<int,int> mapper;
    int coinChange(vector<int>& coins, int amount) {
        return rec(coins,amount);
    }
    
    int rec(vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return -1;
        }
        
        if(mapper.find(amount)!=mapper.end()) return mapper[amount];
        
        int min = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int res= rec(coins,amount-coins[i]);
            if(res>=0 && res<min){
                min=res+1;
            }
        }
        min = min==INT_MAX ? -1:min;
        mapper[amount] = min;
        return mapper[amount];
    }
};