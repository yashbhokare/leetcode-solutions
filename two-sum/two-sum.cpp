class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapper;
        for(int i=0;i<nums.size();i++){
            int newNum = target - nums[i];
            if(mapper.find(newNum)!=mapper.end()){
                return {i,mapper[newNum]};
            }
            mapper[nums[i]] = i;
        }
        return {};
    }
};