class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int end =INT_MIN;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i]+i >=end){
                end = i;
            }
        }

        return end==0;
    }
};