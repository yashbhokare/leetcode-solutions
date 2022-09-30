class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // return sortValuesAndCompare(nums);
       return hashTableApproach(nums);
    }
    
    bool sortValuesAndCompare(vector<int> nums){
        // Sorting approach
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() -1;i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
    
        bool hashTableApproach(vector<int> nums){
        // Using Hash Table 
         unordered_set <int> numSet;
        for(int i=0;i<nums.size();i++){
            //  find returns end iterator if key is not found,
            //  else it returns iterator to that key
            if(numSet.find(nums[i]) == numSet.end()) {
                numSet.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};