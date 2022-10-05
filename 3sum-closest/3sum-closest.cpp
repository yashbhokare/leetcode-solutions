class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(left!=i+1 && nums[left]==nums[left-1]) {
                    left++;
                    continue;
                };
                
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(sum-target)<abs(diff)){
                    diff = sum - target;
                }
                if(target==sum){
                    return sum;
                }else if(sum>target){
                    right--;
                }else {
                    left++;
                }
                
            }
        }
        cout<<diff;
        return diff+target;
    }
};