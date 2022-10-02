class Solution {
public:
    int mod = 1000000007;
    int memo[31][1001] = {};
    int dp[32][1002];
    // unordered_map<int,unordered_map<int,int>> memo;
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return rec(n,k,target);
    }
    
    int rec(int n,int k,int current){
        
        // if (n == 0 || current <= 0) return n == current;
        if(n==0 && current==0 ){
            return 1;
        }
        if(n<=0 || current<0){
            return 0;
        }

        if(dp[n][current]!=-1) return dp[n][current];
        
        if(memo[n][current]==1) return 0;

        int ans = 0;
       
        for(int nums=1;nums<=k;nums++){
            ans=(ans%mod+rec(n-1,k,current-nums)%mod)%mod;
        }
        dp[n][current]=ans;
        return dp[n][current];
    }
};