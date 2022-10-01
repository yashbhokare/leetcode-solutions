class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int longest = INT_MIN;
        int curr = 0;
        for(auto num:nums){
            curr = max(curr+num,num);
            longest = max(longest,curr);
        }
        return longest;
    }
};
////Kadane's Algorithm.