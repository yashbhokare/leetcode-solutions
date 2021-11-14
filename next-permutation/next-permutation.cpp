class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int swapIndex = -1;
        int minElement = INT_MAX;
        int minElementIndex = 0;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                swapIndex = i-1;
                break;
            }
        }
        cout<<swapIndex;
        if(swapIndex >=0){
            int givenValue = nums[swapIndex];
            for(int i=swapIndex+1;i<nums.size();i++){
                if(nums[i] > givenValue && nums[i]<=minElement){ // nums[i]<=minElement is important if we are using reverse logic
                    minElement = nums[i];
                    minElementIndex = i;
                }
            }
            swap(nums[swapIndex],nums[minElementIndex]);
        }


        reverse(nums.begin()+swapIndex+1,nums.end());
    }
};