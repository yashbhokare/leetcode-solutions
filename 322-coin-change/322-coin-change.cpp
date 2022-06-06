class Solution {
public:
    unordered_map<int,int> mapperMemo;
    int coinChange(vector<int>& coins, int amount) {
        return rec(coins,amount);
    }
    
    int rec(vector<int>& coins,int remaining){
        if(remaining==0){
            // result++;
            return 0;
        }
        if(remaining<0){
            return -1;
        }
        
        if(mapperMemo.find(remaining)!=mapperMemo.end()) return mapperMemo[remaining];
        int min=INT_MAX;
        
        for(auto& coin:coins){
            int res=rec(coins,remaining-coin);
            if(res>=0 && res<min){
                min=res+1;
            }
        }
        min = min==INT_MAX ? -1:min;
        mapperMemo[remaining]=min;
        return mapperMemo[remaining];
    }
};