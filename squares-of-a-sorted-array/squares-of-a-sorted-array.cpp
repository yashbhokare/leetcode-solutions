class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int resultPoint = nums.size()-1;
        int left=0,right=nums.size()-1;
        while(left<=right){
            if(abs(nums[left])<=abs(nums[right])){
                result[resultPoint] = nums[right]*nums[right];
                right--;
            }else {
                result[resultPoint] = nums[left]*nums[left];
                left++;
            }
            resultPoint--;
        }
        return result;
    }
};