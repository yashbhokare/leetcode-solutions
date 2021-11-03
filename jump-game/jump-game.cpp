class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int lastIndex = nums.size()-1;
        for(int i=lastIndex-1;i>=0;i--){
                if(nums[i]+i >=lastIndex){
                    lastIndex = i;
                }
        }
        return lastIndex==0;
    }
};