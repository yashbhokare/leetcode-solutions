class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result(nums.size());
        int left=0,right=nums.size()-1;
        for(auto& num:nums){
            if(num%2==0) result[left++]=num;
            else result[right--]=num;
        }
        return result;
    }
};