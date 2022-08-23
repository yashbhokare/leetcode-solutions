class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[i-1]){
                for(auto res:twoSumSorted(nums,i+1,nums.size()-1,-nums[i])){
                   res.push_back(nums[i]);
                   result.push_back(res);
               }
            }
        }
        return result;
        
    }
    vector<vector<int>> twoSumSorted(vector<int>& nums,int low,int high,int target){
        vector<vector<int>> result;
        int start = low;
        int end = high;
        while(low<high){

            if(low!=start && nums[low]==nums[low-1]) {
                low++;
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