class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        int maxPos = n;
        for(int i=n;i>=0;i--){
            if(nums[i] + i >= maxPos){
                maxPos = i;
            }
        }
        return maxPos == 0;
    }
};