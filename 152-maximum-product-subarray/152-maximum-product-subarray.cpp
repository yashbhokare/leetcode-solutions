class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return maxProductUsingDP(nums);
        int maximum = INT_MIN;
        int product = 1;
        for(int i=0;i<nums.size();i++){
            product=product*nums[i];
            maximum = max(maximum,product);
            if(product==0) {
                product=1;
            }
        }
        
        product = 1;
        for(int i=nums.size()-1;i>=0;i--){
            product=product*nums[i];
            maximum = max(maximum,product);
            if(product==0) {
                product=1;
            }
        }
        
        return maximum;
    }
    
     int maxProductUsingDP(vector<int>& nums) {
         int min_so_far = nums[0];
         int max_so_far = nums[0];
         int maximum = nums[0];
         for(int i=1;i<nums.size();i++){
             int multi_min = min_so_far*nums[i];
             int multi_max = max_so_far*nums[i];
             min_so_far = min(min(nums[i],multi_min),multi_max);
             max_so_far = max(max(nums[i],multi_max),multi_min);
             maximum = max(maximum,max_so_far);
         }
         return maximum;
     }
};