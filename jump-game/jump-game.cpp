class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =  nums.size();
        int maxIndex = n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=maxIndex){
                maxIndex =i;
            }
        }
        return maxIndex==0;
    }
};