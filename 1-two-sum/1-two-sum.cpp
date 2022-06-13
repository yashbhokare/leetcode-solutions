class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSumCal(nums,target);
    }
    
    vector<int> twoSumCal(vector<int>& nums, int target){
        unordered_map<int,int> mapper;
        for(int i=0;i<nums.size();i++){
            
            int total = target- nums[i];
            
            if(mapper.find(total)!=mapper.end()){
                return {mapper[total],i};
            }
            mapper[nums[i]]=i;
        }
        return {};
    }
};