class Solution {
public:
    int myAtoi(string s) {
        int index = s.find_first_not_of(' ');
        if(index==-1) index=0; 
        int sign = 1;
        long int result = 0;
        if(s[index]=='+'|| s[index]=='-'){
            sign = s[index++]=='-' ? -1 : 1;
        }
        while(index<s.size() && s[index]>='0' && s[index]<='9'){
            result = result*10 + s[index++]-'0';
            if(sign*result >= INT_MAX) return INT_MAX;
            if(sign*result <= INT_MIN) return INT_MIN;
        }
        return result*sign;
    }
};