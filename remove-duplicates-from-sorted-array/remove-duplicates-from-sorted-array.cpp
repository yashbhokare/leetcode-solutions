class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int startPos = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[startPos]){
                startPos++;
                nums[startPos] = nums[i];
            }
        }
        return startPos+1;
    }
};