class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxResult=INT_MIN;
        int count = 0;
        for(auto num:nums){
            count = max(num,count+num);
            maxResult = max(maxResult,count);
        }
        return maxResult;
    }
};

//Kadane's Algorithm.