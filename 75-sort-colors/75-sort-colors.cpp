class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int two=nums.size()-1;
        int mid=0;
        while(mid<=two){
            if(nums[mid]==0){
                swap(nums[mid],nums[zero++]);
            }else if(nums[mid]==2){
                swap(nums[mid],nums[two--]);
            }else {
                mid++;
            }
            mid = max(mid,zero);
        }
    }
};