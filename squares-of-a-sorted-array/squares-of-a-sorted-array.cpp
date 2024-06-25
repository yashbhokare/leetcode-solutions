class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left=0,right=n-1;
        vector<int> result(n);
        int len=n-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                result[len--]=nums[left]*nums[left];
                left++;
            }else{
                result[len--]=nums[right]*nums[right];
                right--;
            }
        }
        return result;
    }
};