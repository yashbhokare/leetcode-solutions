class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int swapIndex = -1;
        int n = nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                swapIndex = i-1;
                break;
            }
        }
        // cout<<swapIndex;
        if(swapIndex>=0){
            int nextHighestVal=INT_MAX;
            int nexSwapIndex = swapIndex;
            for(int i=swapIndex+1;i<n;i++){
                if(nums[i]>nums[swapIndex] && nums[i]<=nextHighestVal){
                    nextHighestVal = nums[i];
                    // cout<<nextHighestVal;
                    nexSwapIndex = i;
                }
            }
          swap(nums[swapIndex],nums[nexSwapIndex]);
            
        }
        reverse(nums.begin()+swapIndex+1,nums.end());
    }
};