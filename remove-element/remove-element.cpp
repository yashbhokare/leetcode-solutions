class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end=nums.size()-1;
        for(int i=0;i<=end;){
            if(nums[i]==val){
                swap(nums[i],nums[end--]);
            }else {
                i++;
            }
        }
        return end+1;
    }
};