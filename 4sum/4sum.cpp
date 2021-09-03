class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        result = kSum(4,nums,0,target);
        return result;
    }
    
    vector<vector<int>> kSum(int k,vector<int>& nums,int startPos,int target){
        vector<vector<int>> result;
        if(nums.size() == startPos) return result;
        
        if(k==2) return twoSumII(nums,startPos,target);
        
        for(int i=startPos;i<nums.size();i++){
            if(i == startPos || nums[i - 1] != nums[i]){
                vector<vector<int>> subset = kSum(k-1,nums,i+1,target - nums[i]);
                for(int k=0;k<subset.size();k++){
                    result.push_back({nums[i]});
                    result.back().insert(end(result.back()), begin(subset[k]), end(subset[k]));
                }
               
            }
            
        }
        return result;
        
    }
    vector<vector<int>> twoSumII(vector<int>& nums, int startPos, int target){
        int low = startPos;
        int high = nums.size()-1;
        vector<vector<int>> result;
        while(low<high){
            int calculate = nums[low] + nums[high];

            if(calculate > target || (high < nums.size()-1 && nums[high] == nums[high+1] )){
                high--;
            } else if(calculate < target || (low > startPos && nums[low] == nums[low-1])) {
                low++;
            }
            else{
                result.push_back({nums[low],nums[high]});
                low++;
                high--;
                // continue;
            }
        }
        return result;
    }
};