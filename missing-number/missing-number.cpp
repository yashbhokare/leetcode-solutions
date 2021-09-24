class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int maxValue = 0;
        
        int givenSum = 0;
        for(int i=0;i<n;i++){
            givenSum+= nums[i];
            maxValue = max(maxValue,nums[i]);
        }
        int sum = ((n+1)*(n))/2;
        return  sum - givenSum;
    }
};