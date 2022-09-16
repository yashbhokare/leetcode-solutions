class Solution {
public:
    double myPow(double x, int n) {
        long N=n;
        if(n<0){
            N=-N;
            x= 1/x;
        }
        return rec(x,N);
    }
    
    double rec(double x, int n){
        if(n==0) return 1;
        double half = rec(x,n/2);
        if(n%2==0){
            return half*half;
        }else {
            return half*half*x;
        }
        
    }
};