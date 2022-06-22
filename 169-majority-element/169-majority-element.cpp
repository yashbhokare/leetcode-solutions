class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majorityElement = nums[0];
        for(auto num:nums){
            if(count==0){
                majorityElement = num;
            }
            if(majorityElement==num) count++;
            else count--;
        }
        return majorityElement;
    }
};