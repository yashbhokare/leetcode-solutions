class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        // cout<<memo[nums.size()-1];
        return rec(nums,nums.size()-1,memo);
    }
    
    int rec(vector<int>& nums,int index,vector<int>& memo){

        if(index==0){
            return nums[0];
        } else if(index ==1){
            return max(nums[0],nums[1]);
        }
        if(memo[index]!=-1){
            return memo[index];
        }
        memo[index] = max(rec(nums,index-1,memo),rec(nums,index-2,memo)+nums[index]);
        return memo[index];
    }
};