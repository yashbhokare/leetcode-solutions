class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left=0,right=n-1;
        vector<int> result;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                result.push_back(nums[left]*nums[left]);
                left++;
            }else{
                result.push_back(nums[right]*nums[right]);
                right--;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};