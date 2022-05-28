class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left=0,right=nums.size()-1;
       while(left<=right){
            if(nums[left]%2==0){
                left++;
            } else{
               swap(nums[left],nums[right]);
                right--;
            };
        }
        return nums;
    }
    
    vector<int> sortArrayByParityWithNewArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int left=0,right=nums.size()-1;
        for(auto& num:nums){
            if(num%2==0) result[left++]=num;
            else result[right--]=num;
        }
        return result;
    }
};