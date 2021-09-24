class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int product = 1;
        bool zero = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0 && !zero){
                zero = true;
            } else {
                // product = product == 0 ? 1 : product;
                product = product * (nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                result.push_back(product);
            }else if(zero) {
                result.push_back(0);
            } 
            else {
                result.push_back(product/nums[i]);
            }
        }
        return result;
    }
};