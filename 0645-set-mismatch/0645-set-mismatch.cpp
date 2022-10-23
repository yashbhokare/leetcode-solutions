class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> uSet;
        int total = 0;
        int expectedTotal = 0;
        int dup = 0;
        for(int i=0;i<nums.size();i++){
            if(uSet.find(nums[i])!=uSet.end()){
                dup = nums[i];
            }else {
                uSet.insert(nums[i]);  
                total+=nums[i];
            }
            expectedTotal+=i+1;
        }
        return {dup,expectedTotal-total};
    }
};