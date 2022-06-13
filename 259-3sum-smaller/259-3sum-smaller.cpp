class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result = 0;
        for(int i=0;i<nums.size();i++){
            int low=i+1;
            int high=nums.size()-1;
            while(low<=high){
                int sum = nums[low]+nums[high]+nums[i];
                if(sum<target){
                   result += high-low;
                    low++;
                }else{
                    high--;
                }
            }
        }
        return result;
    }
};