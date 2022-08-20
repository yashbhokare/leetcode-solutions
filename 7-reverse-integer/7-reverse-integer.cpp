class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        int newX = 0;
        while(x!=0){
            if(newX > INT_MAX/10 || (newX==INT_MAX/10 && x%10>7)) return 0;
            if(newX < INT_MIN/10 || (newX==INT_MIN/10 && x%10==-9)) return 0;
                
            int rev = x%10;
            newX = newX*10 + rev;
            x= x/10;
        }
        return newX;
    }
};