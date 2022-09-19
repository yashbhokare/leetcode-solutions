class Solution {
public:
    int myAtoi(string s) {
        int index=s.find_first_not_of(' ');
        if(index==-1) return 0;
        int sign = 1;
        if(s[index]=='+' || s[index]=='-'){
            sign = s[index]=='-' ? -1 : 1; 
            index++;
        }
        int result = 0;
        while(s[index]>='0' && s[index]<='9'){
            int digit =s[index]-'0';
            // Check overflow and underflow conditions. 
            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.    
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result*10 + digit;
            index++;
        }
        return result*sign;
        
    }
};