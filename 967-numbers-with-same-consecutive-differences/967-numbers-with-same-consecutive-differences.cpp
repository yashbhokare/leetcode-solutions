class Solution {
public:
    vector<int> result;
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            dfs(n-1,k,i);
        }
        return result;
    }
    
    void dfs(int n,int k,int num){
        if(n==0){
            result.push_back(num);
            return;
        }
        
        int lastDigit = num%10;
        int nextFirstDigit = lastDigit+k;
        if(nextFirstDigit<10){
            int newNum = num*10 + nextFirstDigit;
            dfs(n-1,k,newNum);
        }
        
        int nextSecondDigit = lastDigit-k;
        if(nextFirstDigit!=nextSecondDigit && nextSecondDigit>=0){
            int newNum = num*10 + nextSecondDigit;
            dfs(n-1,k,newNum);
        }
        
    }
};