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
    
    void backtrack(vector<int> nums, int first,vector<vector<int>>& result){
        if(first == nums.size()){
            result.push_back(nums);
        }
        
        for(int i=first;i<nums.size();i++){
            swap(nums[first],nums[i]);
            backtrack(nums,first+1,result);
        }
    }
};