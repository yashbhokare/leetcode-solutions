class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        vector<int> result;
        for(int i=0;i<nums.size();i+=k){
            
            int j=i;
            
            int n=i+k-1;
            n = n >= nums.size() ? nums.size()-1 : n;
            int lastElement = n;
            while(j<i+k && j<nums.size()){
                // cout<<j<<" ";
                // Maximum from left->right
                if(j==i){
                    left[j]=nums[j];
                }else {
                    left[j] = max(nums[j],left[j-1]);
                }
                // Moving from right->left
                if(n==lastElement){
                    right[n] = nums[n];
                }else {
                    right[n] = max(nums[n],right[n+1]);
                }
                
                j++;
                n--;
            }
            
        }
        
        for(int i=0;i<=nums.size()-k;i++){
                result.push_back(max(left[i+k-1],right[i]));
        }
        return result;
    }
};