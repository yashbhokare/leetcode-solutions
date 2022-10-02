class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int minJump =n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=minJump){
                minJump = i;
            }
        }
        return minJump==0;
    }
};