class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        rec(0,nums);
        return result;
    }
    
    void rec(int index,vector<int>& nums){
        if(index==nums.size()-1){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            rec(index+1,nums);
            swap(nums[i],nums[index]);
        }
    }
};