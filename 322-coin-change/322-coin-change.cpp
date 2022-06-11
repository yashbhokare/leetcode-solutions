class Solution {
public:
    int result=INT_MAX;
    unordered_map<int,int> mapper;
    int coinChange(vector<int>& coins, int amount) {
        return rec(coins,amount,0,0);
        // return result==INT_MAX ? -1 : result;
    }
    
    int rec(vector<int>& coins, int amount,int total,int start){
        // cout<<amount<<" "<<total<<" "<<coins[start]<<endl;
        if(amount==0){
            // result=min(result,total);
            cout<<total<<endl;
            return 0;
        }else if(amount<0){
            return -1;
        }
        
        if(mapper.find(amount)!=mapper.end()) return mapper[amount];
        
        int min= INT_MAX;
        for(int i=0;i<coins.size();i++){
            int val=rec(coins,amount-coins[i],total+1,i);
            if(val>=0 && val<min){
                min=val+1;
            }
        }

        mapper[amount] = min==INT_MAX ? -1 : min;
        return mapper[amount];
    }
};