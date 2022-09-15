class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int minElem = INT_MAX;
            int minIndex = i; 
            for(int j=i;j<nums.size();j++){
                if(nums[j]<minElem){
                    minElem = nums[j];
                    minIndex = j;
                }
            }
            swap(nums[i],nums[minIndex]);
        }
    }
};