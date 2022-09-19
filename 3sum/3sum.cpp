class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums),end(nums));
        return kthSum(nums,0,0,nums.size()-1,3);
        // for(int i=0;i<nums.size();i++){
        //     if(i!=0 && nums[i]==nums[i-1]) continue;
        //     int target = -nums[i];
        //     for(auto arr:twoSumSorted(nums,i+1,nums.size()-1,target)){
        //         arr.push_back(nums[i]);
        //         ans.push_back(arr);
        //     }
        // }
        // return ans;
    }
    
    vector<vector<int>> kthSum(vector<int>& nums,int target,int start,int end,int k){
        if(start>end){
            return {};
        }
        if(k==2){
            return twoSumSorted(nums,start,end,target);
        }else {
            vector<vector<int>> result;
            for(int i=start;i<=end;i++){
                if(i!=start && nums[i]==nums[i-1]) continue;
                int sum = target - nums[i];
                vector<vector<int>> ans = kthSum(nums,sum,i+1,end,k-1);
                for(auto arr:ans){
                    arr.push_back(nums[i]);
                    result.push_back(arr);
                }
            }
            return result;
        }
       
    }
    
    
    vector<vector<int>> twoSumSorted(vector<int>& nums,int start,int end,int target){
        vector<vector<int>> result;
        int low=start;
        int high =end;
        while(low<high){
            if(low!=start && nums[low]==nums[low-1]) {
                low++;
                continue;
            }
            if(high!=end && nums[high]==nums[high+1]){
                high--;
                continue;
            }
           
            int sum = nums[low]+nums[high];
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