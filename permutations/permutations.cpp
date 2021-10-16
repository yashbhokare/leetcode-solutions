class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 2) {
            result.push_back(nums);
            return result;
        } 
        backtrack(nums,0,result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int pos,vector<vector<int>>& result){
        if(pos == nums.size()){
            result.push_back(nums);
        }
        
        for(int i=pos;i<nums.size();i++){
            swap(nums[pos],nums[i]);
            backtrack(nums, pos+1,result);
            // Backtrack the same number
            swap(nums[pos],nums[i]);
        }
    }
};