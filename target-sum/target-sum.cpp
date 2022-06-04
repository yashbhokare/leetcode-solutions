class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int result=0;
        recTargetSum(nums,target,0,result);
        return result;
    }
    
    void recTargetSum(vector<int>& nums, int target,int index,int& result){
        if(index==nums.size()){
            if(target==0){
                result++;
            }
            return;
        }
        int newSum=target-nums[index];
        int newSum2=target+nums[index];
        recTargetSum(nums,newSum,index+1,result);
        recTargetSum(nums,newSum2,index+1,result);
    }
};