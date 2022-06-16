class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 2) return {};
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(i!=0 && nums[i]==nums[i-1]){
               continue;
            }
            int target = -nums[i];
            twoSumII(nums,i+1,nums.size()-1,target);
        }
        return result;
    }
    
    void twoSumII(vector<int>& nums,int start,int end,int target){
        int left = start;
        int right = end;
        while(left<right){
            if(left!=start && nums[left]==nums[left-1]) {
                left++;
                continue;
            }
            
            if(right!=end && nums[right]==nums[right+1]){
                right--;
                continue;
            }
            
            int sum = nums[left]+nums[right];
            
            if(sum<target){
                left++;
            }else if(sum>target){
                right--;
            }else {
                result.push_back({-target,nums[left],nums[right]});
                left++;
                right--;
            }
        }
    }
};