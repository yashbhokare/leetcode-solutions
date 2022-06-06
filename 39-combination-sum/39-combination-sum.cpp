class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> total;
        rec(candidates,target,0,0,total);
        return result;
    }
    
    void rec(vector<int>& candidates,int target,int sum,int start,vector<int> total){
        if(sum==target){
            result.push_back(total);
            return;
        }else if(sum>target){
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            total.push_back(candidates[i]);
            rec(candidates,target,sum+candidates[i],i,total);
            total.pop_back();
        }
        
    }
};