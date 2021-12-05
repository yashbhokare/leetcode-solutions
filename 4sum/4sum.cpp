class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(4,0,nums,target);
    }
    
    vector<vector<int>> kSum(int k,int pos,vector<int>& nums,int target){
        if(k==2) return twoSum(pos,nums,target);
        vector<vector<int>> result;
        for(int i=pos;i<nums.size();i++){
            if(i==pos || nums[i]!=nums[i-1]){
                int newtarget = target-nums[i];
                vector<vector<int>> givenKSum = kSum(k-1,i+1,nums,newtarget);
                for(auto &array:givenKSum){
                    array.insert(array.begin(),nums[i]);
                    result.push_back(array);
                }
            }

        }
        return result;
    }
    
    
    vector<vector<int>> twoSum(int index,vector<int>& nums,int target){
        vector<vector<int>> result;
        int start = index;
        int last = nums.size()-1;
        while(start<last){
            int sum = nums[start] + nums[last];
            if(sum < target || (start > index && nums[start] == nums[start-1])){
                start++;
            }
            else if(sum > target || (last < nums.size()-1 && nums[last] == nums[last+1])){
                last--;
            } else {
                result.push_back({nums[start],nums[last]});
                start ++;
                last--;
            }
        }
        return result;
    }
};