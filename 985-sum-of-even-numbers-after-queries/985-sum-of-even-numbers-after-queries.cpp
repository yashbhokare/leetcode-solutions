class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumEvenNums = 0;
        for(auto n:nums) if(n%2==0) sumEvenNums+=n;
        vector<int> result;
        for(auto q:queries){
            bool isEven = false;
            int index= q[1];
            int value = q[0];
            if(nums[index]%2==0){
                sumEvenNums-=nums[index];
            }
            int newValue = nums[index]+value;
            if(newValue%2==0){
                sumEvenNums+=newValue;
            }
            // cout<<sumEvenNums<<" ";
            result.push_back(sumEvenNums);
            nums[index] = newValue;
        }
        return result;
    }
};