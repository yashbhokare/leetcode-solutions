class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(n<0){
            N=abs(n);
            x=1/x;
        }
        return rec(x,N);
    }
    
    
    double rec(double x,long long n){
        if(n==0) return 1;
        double half = rec(x,n/2);
        
        if(n%2==0) 
            return half*half;
        else 
            return half*half*x;
    }
};