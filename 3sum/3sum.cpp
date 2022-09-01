class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[i-1]){
                vector<vector<int>> currRes = twoSumSorted(nums,i+1,-nums[i]);
                for(auto val:currRes){
                    // cout<<val.size();
                    val.push_back(nums[i]);
                    ans.push_back(val);
                }
            }
           
        }
        return ans;
    }
    
    vector<vector<int>> twoSumSorted(vector<int>& nums,int start, int target){
        vector<vector<int>> result;
        int low = start;
        int high = nums.size()-1;
        while(low<high){
            int total = nums[low]+nums[high];
            
            if(low!=start && nums[low]==nums[low-1]){
                low++;
                continue;
            }
            if(high!=nums.size()-1 && nums[high]==nums[high+1]){
                high--;
                continue;
            }
            
            if(total==target){
                result.push_back({nums[low],nums[high]});
                low++;
                high--;
            }else if(total>target){
                high--;
            }else {
                low++;
            }
        }
        return result;
    }
};