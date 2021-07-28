class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int lastIndex = 0 ;
        for(int i= 1; i < nums.size();i++){
                if(nums[i] != nums[lastIndex]){
                    lastIndex++;
                    nums[lastIndex] = nums[i];
                } 
        }
        return lastIndex+1;
    }
};