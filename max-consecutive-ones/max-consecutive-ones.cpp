class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result=0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                count++;
            }else {
                count = 0;
            }
            result = max(result,count);
        }
        return result;
    }
};