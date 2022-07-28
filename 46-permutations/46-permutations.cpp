class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        rec(nums,0);
        return ans;
    }
    
    void rec(vector<int>& nums, int start){
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            rec(nums,start+1);
            swap(nums[start],nums[i]);
        }
    }
};