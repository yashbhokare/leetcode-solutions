class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool consecutive=false;
        int count=0;
        int result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] && !consecutive){
                consecutive=true;
                count=1;
            }else if(consecutive && nums[i]){
                count++;
            }else{
                consecutive=false;
                count=0;
            }
            result=max(result,count);
        }
        return result;
    }
};