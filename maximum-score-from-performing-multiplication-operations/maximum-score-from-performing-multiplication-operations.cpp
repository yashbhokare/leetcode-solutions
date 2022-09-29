class Solution {
public:
    unordered_map<int,unordered_map<int,int>> cache;
    int n;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n=nums.size();
        return dp(nums,multipliers,0,0);
    }
    
    
    int dp(vector<int>& nums, vector<int>& multipliers,int multi_index,int left){
        if(multi_index==multipliers.size()){
            return 0;
        }
        
        int right = (n-1)-(multi_index-left);
        int left_multi = multipliers[multi_index]*nums[left];
        int right_multi = multipliers[multi_index]*nums[right];
        if(cache[multi_index][left]==0){
            cache[multi_index][left] = max(left_multi + dp(nums,multipliers,multi_index+1,left+1),
                                           right_multi + dp(nums,multipliers,multi_index+1,left));
        }
        return cache[multi_index][left];
    }
    
};