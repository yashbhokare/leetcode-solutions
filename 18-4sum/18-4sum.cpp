class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kthSum(nums,target,0,nums.size()-1,4);
    }
    
     vector<vector<int>> kthSum(vector<int>& nums,long target,long start,long end,long k){
        if(start>=end){
            return {};
        }
        if(k==2){
            return twoSumSorted(nums,start,end,target);
        }else {
            vector<vector<int>> result;
            for(long i=start;i<=end;i++){
                if(i!=start && nums[i]==nums[i-1]) continue;
                long sum = target - nums[i];
                vector<vector<int>> ans = kthSum(nums,sum,i+1,end,k-1);
                for(auto arr:ans){
                    arr.push_back(nums[i]);
                    result.push_back(arr);
                }
            }
            return result;
        }
       
    }
    
    
    vector<vector<int>> twoSumSorted(vector<int>& nums,long start,long end,long target){
        vector<vector<int>> result;
        long low=start;
        long high =end;
        while(low<high){
            if(low!=start && nums[low]==nums[low-1]) {
                low++;
                continue;
            }
            if(high!=end && nums[high]==nums[high+1]){
                high--;
                continue;
            }
           
            long sum = nums[low]+nums[high];
            if(sum==target){
                result.push_back({nums[low],nums[high]});
                low++;
                high--;
            }else if(sum>target){
                high--;
            }else {
                low++;
            }
        }
        return result;
    }
};