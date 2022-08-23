class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int swapIndex = -1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                swapIndex = i-1;
                break;
            }
        }
        // cout<<swapIndex;
        if(swapIndex>=0){
            int minVal = INT_MAX;
            int minIndex = swapIndex;
            for(int i=swapIndex+1;i<nums.size();i++){
                if(nums[i]>nums[swapIndex] && nums[i]<=minVal){
                    minVal = nums[i];
                    minIndex = i;
                }
            }
            // cout<<minIndex;
            swap(nums[minIndex],nums[swapIndex]);
        }
        reverse(nums.begin()+swapIndex+1,nums.end());
    }
};