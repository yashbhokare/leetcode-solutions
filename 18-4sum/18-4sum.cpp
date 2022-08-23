class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kthSum(nums,4,0,target);
    }
    
    vector<vector<int>> kthSum(vector<int>& nums,int k, int low,long int target){
        if(low>=nums.size()) return {};
        
        // There are k remaining values to add to the sum. The 
        // average of these values is at least target / k.
        int average_value = target / k;
        
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest 
        // value in nums is smaller than target / k.
        if  (nums[low] > average_value || average_value > nums.back()) {
            return {};
        };
        
        
        if(k==2){
            return twoSumSorted(nums,low,target);
        }else {
            vector<vector<int>> ans;
            for(int i=low;i<nums.size();i++){
                if(i==low || nums[i]!=nums[i-1]){
                    vector<vector<int>> result = kthSum(nums,k-1,i+1,target-nums[i]);
                    for(auto res:result){
                        res.push_back(nums[i]);
                        ans.push_back(res);
                    }
                }
            }
            return ans;
        }
    }
    
    vector<vector<int>> twoSumSorted(vector<int>& nums,int low,int target){
        vector<vector<int>> result;
        int start = low;
        int high = nums.size()-1;
        while(low<high){
            if(low!=start && nums[low]==nums[low-1]) {
                low++;
                continue;
            }
            if(high!=nums.size()-1 && nums[high]==nums[high+1]) {
                high--;
                continue;
            }
            
            int sum = nums[low] + nums[high];
            if(sum==target){
                result.push_back({nums[low],nums[high]});
                low++;
                high--;
            }else if(sum<target){
                low++;
            }else {
                high--;
            }
        }
        return result;
    }
};