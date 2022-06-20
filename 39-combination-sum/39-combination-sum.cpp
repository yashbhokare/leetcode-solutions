class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> val;
        rec(candidates,target,val,0);
        return result;
    }
    
    void rec(vector<int>& candidates,int target,vector<int> total,int start){
        if(target==0){
            result.push_back(total);
            return;
        }else if(target<0){
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            total.push_back(candidates[i]);
            rec(candidates,target-candidates[i],total,i);
            total.pop_back();
        }
    }
};