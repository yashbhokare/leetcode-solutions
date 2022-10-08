class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff  = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int left = i+1;
            int right = nums.size()-1;
            while(i+1<nums.size() && left<right){
                if(left!=i+1 && nums[left-1]==nums[left]){
                    left++;
                    continue;
                }
                int sum = nums[left]+nums[right]+nums[i];
                if(abs(sum-target)<abs(diff)){
                    diff = sum-target;
                }
                if(sum==target) return sum;
                else if(sum>target){
                    right--;
                }else{
                    left++;
                } 
            }
        }
        return diff+target;
    }
};