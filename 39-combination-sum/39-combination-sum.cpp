class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        rec(candidates,target,0,arr);
        return result;
    }
    
    void rec(vector<int>& candidates,int target,int index, vector<int>& arr){
        if(index>=candidates.size() || target<0) return;
        
        if(target==0){
            result.push_back(arr);
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            arr.push_back(candidates[i]);
            rec(candidates,target-candidates[i],i,arr);
            arr.pop_back();
        }
    }
};