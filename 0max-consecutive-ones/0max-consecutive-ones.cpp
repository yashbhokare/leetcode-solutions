class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result=0,count=0;
        for(int num:nums){
            count = num ? count+1 : 0;
            result=max(result,count);
        }
        return result;
    }
};