class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int constantSum = 1;
        int index=1;
        int result=0;
        while(constantSum<=n){
            if((n-constantSum)%index==0){
                result++;
            }
            index++;
            constantSum+=index;
        }
        return result;
    }
};