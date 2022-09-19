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
        long result = 0;
        while(s[index]>='0' && s[index]<='9'){
            result = result*10 + (s[index]-'0');
            index++;
            if(result*sign>=INT_MAX) return INT_MAX;
            if(result*sign<=INT_MIN) return INT_MIN;
        }
        return result*sign;
        
    }
};