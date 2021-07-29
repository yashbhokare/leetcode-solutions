class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return bitManipulation(nums);
    }
    
    int hashTable(vector<int> nums){
        unordered_set <int> numSet;
        for(int i=0; i< nums.size(); i++){
            if(numSet.find(nums[i]) == numSet.end()){
                numSet.insert(nums[i]);
            } else {
                numSet.erase(nums[i]);
            }
        }
        return *numSet.begin();
    }
    
    int bitManipulation(vector<int> nums){
        int num = 0;
        for(int i=0; i< nums.size(); i++){
            num = num ^ nums[i];
        }
        return num;
    }
};