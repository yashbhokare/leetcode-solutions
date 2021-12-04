class Solution {
public:
    int m,n;
    vector<vector<int>> memo;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        memo.resize(m+1,vector<int>(m+1,0));
        return dp(0,0,nums,multipliers);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<m;j++){
        //             cout<<memo[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return memo[0][0];
    }
    
    int dp(int i, int left,vector<int>& nums, vector<int>& multipliers){
        if(i>=m){
            return 0;
        }
         if(memo[i][left]!=0){
           return memo[i][left];
        }
        int multi = multipliers[i];
        int right = (n-1)-(i-left);
        if(memo[i][left]==0){
            memo[i][left] = max(multi*nums[left] + dp(i+1,left+1,nums,multipliers),
                                multi*nums[right] + dp(i+1,left,nums,multipliers));
        }
        return memo[i][left];
    }
};