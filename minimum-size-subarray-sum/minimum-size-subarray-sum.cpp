class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0;
        int right=0;
        int result=INT_MAX;
        int total=0;
        while(right<nums.size()){
            total+=nums[right];
            while(total>=target){
                result=min(result,right-left+1);
                total-=nums[left];
                left++;
            }
            right++;
        }
        return result==INT_MAX ? 0 : result;
        
    }
};