class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result=0,count=0;
        for(int num:nums){
            if(num) {
                count++;
                result=max(result,count);
            }else {
                count=0;
            }
        }
        return result;
    }
};