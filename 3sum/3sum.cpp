class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        // return kthSum(nums,3,0,0);
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[i-1]){
                vector<vector<int>> currRes = twoSumSorted(nums,i+1,-nums[i]);
                for(auto val:currRes){
                    val.push_back(nums[i]);
                    ans.push_back(val);
                }
            }
           
        }
        return ans;
    }
    
    vector<vector<int>> kthSum(vector<int>& nums, int k, int index, int target){
        if(index>=nums.size()) return {};
        
        if(k==2){
            return twoSumSorted(nums,index,target);
        }
        
        vector<vector<int>> ans;
        for(int i=index;i<nums.size();i++){
            if(i==index || nums[i]!=nums[i-1]){
                vector<vector<int>> currRes = kthSum(nums,k-1,i+1, target-nums[i]);
                for(auto val:currRes){
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