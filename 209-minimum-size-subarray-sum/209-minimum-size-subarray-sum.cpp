class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right=0;
        int left=0;
        int total=0;
        int result=INT_MAX;
        while(right<nums.size()){
            total+=nums[right];
            while(total>=target){
                result=min(result,right-left+1);
                total-=nums[left];
                left++;
            }
            right++;
        }
        if(result==INT_MAX) return 0;
        else return result;
    }
};