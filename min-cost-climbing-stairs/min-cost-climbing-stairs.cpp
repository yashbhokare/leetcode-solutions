class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
       
        cost.push_back(0);
        memo.resize(cost.size(),INT_MAX);
        return rec(cost.size()-1,cost);
        for(auto& it:memo){
            cout<<it<<" ";
        }
        return 0;
    }
    
    int rec(int index,vector<int>& cost){
        if(index==0){
            return cost[0];
        }
        if(index==1){
            return cost[1];
        }
        if(memo[index]!=INT_MAX) return memo[index];
        memo[index] = min(rec(index-1,cost),rec(index-2,cost))+cost[index];
        return memo[index];
    }
};