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
            //Assigning new value to the given index
            nums[index] = nums[index]+value;
            if(nums[index]%2==0){
                sumEvenNums+=nums[index];
            }
            result.push_back(sumEvenNums);
        }
        return result;
    }
};