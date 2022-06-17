class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mapper;
        for(auto num:nums){
            mapper[num]++;
            if(mapper[num]>n/2) return num;
        }
        return 0;
    }
};