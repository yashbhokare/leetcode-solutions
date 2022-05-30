class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        // return twoSum(nums,0,1);
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1] ){
                continue;
            }
            int target = -nums[i];
            vector<vector<int>> res = twoSum(nums,i+1,target);
            for(int k=0;k<res.size();k++){
                // Append the target to given result
                res[k].push_back(nums[i]);
                // Append the total pair to final ans array
                ans.push_back(res[k]);
            }
        }
        return ans;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums,int start,int target){
        vector<vector<int>> result;
        int lastPos = nums.size()-1;
        int startPos = start;
        while(startPos<lastPos){
            if(startPos!=start && nums[startPos]==nums[startPos-1]){
                startPos++;
                continue;
            }
            if(lastPos!=nums.size()-1 && nums[lastPos]==nums[lastPos+1]){
                lastPos--;
                continue;
            }
            int sum = nums[startPos]+nums[lastPos];
            if(sum==target){
                result.push_back({nums[startPos],nums[lastPos]});
                startPos++;
                lastPos--;
            }
            else if(sum<target){
                startPos++;
            }else {
                lastPos--;
            }
        }
        return result;
    }
};