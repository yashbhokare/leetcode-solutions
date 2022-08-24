class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        rec(nums,0);
        return result;
    }
    
    void rec(vector<int>& nums,int index){
        if(index==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            rec(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
};