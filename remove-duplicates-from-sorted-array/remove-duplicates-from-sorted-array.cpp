class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int head=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[head]){
                nums[++head]=nums[i];
            }
        }
        return head+1;
    }
};