class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapper;
        for(int i=0;i<nums.size();i++){
            int value = target - nums[i];
            if(mapper.find(value)!=mapper.end()){
                return { mapper[value], i };
            }else {
                mapper[nums[i]] = i;
            }
        }
        return {};
    }
};