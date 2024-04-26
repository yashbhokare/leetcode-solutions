class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mapper;
        for(int i=0;i<nums.size();i++){
            if(mapper.count(nums[i])>0 && i-mapper[nums[i]]<=k) return true;
            else mapper[nums[i]]=i; 
        }
        return false;
    }
};