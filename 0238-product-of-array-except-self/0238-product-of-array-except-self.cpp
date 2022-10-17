class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int rightMulti = 1;
        vector<int> result(n,1);
        
        for(int i=1;i<n;i++) result[i] = result[i-1]*nums[i-1];
        
        for(int i=n-1;i>=0;i--) {
            result[i] = result[i]*rightMulti;
            rightMulti = rightMulti*nums[i];
        }
        
        return result;
    }
};