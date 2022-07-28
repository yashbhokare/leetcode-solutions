class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recursion(candidates,{},target,0);
        return ans;
    }
    
    void recursion(vector<int>& candidates,vector<int> result,int target,int start){
        if(target==0){
            ans.push_back(result);
            return;
        }
        if(target<0) return;
        
        for(int i=start;i<candidates.size();i++){
            result.push_back(candidates[i]);
            recursion(candidates,result,target-candidates[i],i);
            result.pop_back();
        }
    }
};