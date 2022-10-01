class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return maxProductUsingDp(nums);
        // return maxProductUsingLeftAndRightTraversal(nums);
    }
    
    // Smart Solution
    int maxProductUsingLeftAndRightTraversal(vector<int>& nums) {
        int product = 1;
        int max_result = INT_MIN;
        for(int i =0;i<nums.size();i++){
            product =product*nums[i];
            max_result = max(max_result,product);
            if(product==0) product=1;
        }
        
        product = 1;
        for(int i =nums.size()-1;i>=0;i--){
            product =product*nums[i];
            max_result = max(max_result,product);
            if(product==0) product=1;
        }
        return max_result;
    }
    
    int maxProductUsingDp(vector<int>& nums) {
        int min_so_far = nums[0];
        int max_so_far = nums[0];
        int result = nums[0];
        for(int i=1;i<nums.size();i++){
            int max_product = max_so_far*nums[i];
            int min_product = min_so_far*nums[i];
            max_so_far = max(max(max_product,nums[i]),min_product);
            min_so_far = min(min(max_product,nums[i]),min_product);
            result = max(result,max_so_far);
        }
        return result;
    }
};