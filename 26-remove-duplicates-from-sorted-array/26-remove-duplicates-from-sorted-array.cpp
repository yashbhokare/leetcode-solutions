class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int count = 1;
        int index = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[index]!=nums[i]){
                index++;
                nums[index]=nums[i];
            }
        }
        return index+1;
    }
};