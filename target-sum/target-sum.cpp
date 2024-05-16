class Solution {
public:
    
    int result=0;
    void recursion(vector<int>& nums,int index,int total,int target){
        if(index==nums.size()){
            if(target==total){
                result++;
            }
            return;
        }
        recursion(nums,index+1,total+nums[index],target);
        recursion(nums,index+1,total-nums[index],target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        recursion(nums,0,0,target);
        return result;
    }
};