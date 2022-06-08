class Solution {
public:
    int result= 0;
    
    int climbStairs(int n) {
        vector<int> memo(n+1);
        return rec(0,n,memo);
        // return result;
    }
    
    int rec(int number,int max,vector<int>& memo){
        if(number==max){
            return 1;
        }
        if(number > max){
            return 0;
        }
        if(memo[number]) return memo[number];  
        memo[number] = rec(number+1,max,memo) + rec(number+2,max,memo);
        return memo[number];
    }
};