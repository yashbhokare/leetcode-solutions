class Solution {
public: 
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        rec(nums,0);
        return result;
    }
    
    void rec(vector<int>& nums,int start){
        if(start==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            rec(nums,start+1);
            swap(nums[i],nums[start]);
        }
    }
};