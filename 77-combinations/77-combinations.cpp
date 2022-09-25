class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        backtrack(1,nums,n,k);
        return result;
    }
    
    void backtrack(int start,vector<int>& nums,int n,int k){
        if(nums.size()==k){
            result.push_back(nums);
            return;
        }
        if(nums.size()>k) return;
        
        for(int i=start;i<=n;i++){
            nums.push_back(i);
            backtrack(i+1,nums,n,k);
            nums.pop_back();
        }
    }
};