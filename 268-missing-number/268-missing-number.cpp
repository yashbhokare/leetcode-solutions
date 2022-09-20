class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int currentTotalSum = accumulate(nums.begin(),nums.end(),0);
        int expectedTotalSum = (n*(n+1))/2;
        return expectedTotalSum-currentTotalSum;
    }
};