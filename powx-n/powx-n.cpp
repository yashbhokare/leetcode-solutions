class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            N = -N;
            x = 1/x;
        }
        return cal(x,N);
    }
    
    double cal(double x, long long n){
        if(n==0) return 1;
        double half = cal(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
        
    }
};