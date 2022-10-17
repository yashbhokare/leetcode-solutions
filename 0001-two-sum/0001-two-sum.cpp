class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_set;
        for(int i=0;i<nums.size();i++){
            int total = target-nums[i];
            if(num_set.find(total)!=num_set.end()){
                return {i,num_set[total]};
            }else {
                num_set[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};