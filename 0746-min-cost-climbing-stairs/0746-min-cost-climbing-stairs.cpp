class Solution {
public:
    unordered_map<int,int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        return dp(cost,cost.size()-1);
    }
    
    int dp(vector<int>& cost, int index){
        if(memo.find(index)!=memo.end()) return memo[index];
        
        if(index==0) return cost[0];
        if(index==1) return cost[1];
        
        memo[index] = min(dp(cost,index-2),dp(cost,index-1)) + cost[index];
        return memo[index];
    }
};