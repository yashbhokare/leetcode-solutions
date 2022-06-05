class Solution {
public:
//     For representing N as sum of consecutive integers we have the following scenarios:

// N = M + 0 (Base case when M == N, or when N is sum of only one number i.e itself)
// N = M + (M + 1) (when N is sum of two consecutive numbers e.g 9 = 4+5, here M is 4 ) => 2M + 1
// N = M + (M+1) + (M+2) (when N is sum of 3 consecutive numbers, e.g 9 = 2+3+4, here M is 2) => 3M + 3
// N = M + (M+1) + (M+2) + (M+3) => 4*M + 6
// N = M + (M+1) + (M+2) + (M+3) + (M+4) => 5M + 10
// N = M + (M+1) + (M+2) + (M+3) + (M+4) + (M + 5) => 6M + 15
// ....... and so on

// so looking at this series we need to find the unique numbers of M such that they fit our equations. (M needs to be an integer)
    int consecutiveNumbersSum(int N) {
        
        int constant_term = 0;
        int divisor = 1;
        int ans = 0;
        while (constant_term < N)
        {
            // if ((N-constant_term)/divisor).is_integer():
            if((N-constant_term)%divisor==0)
                ans += 1;
            
            constant_term = constant_term + divisor;
            divisor += 1;
        }
        return ans;
    }
};