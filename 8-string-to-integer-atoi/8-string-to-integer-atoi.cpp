class Solution {
public:
//     int myAtoi(string s) {
//         return myAtoiLogic(s);
//     }
    
//     int myAtoiLogic(string s) {
//         int signOfInteger = 0;
//         int number = 0;
//         bool isDigit = false;
//         for(int i=0;i<s.length();i++){
//             if(isDigit && !isdigit(s[i])) break;
//             if(s[i] == ' ') continue;
//             if(s[i] == '-') {
//                 signOfInteger = -1;
//                 isDigit = true;
//                 continue;
//             }
//              if(s[i] == '+') {
//                 signOfInteger = 1;
//                 isDigit = true;
//                 continue;
//              }
            
//             if(isalpha(s[i])) break;
//             if(s[i] == '.') break;
//             if(isdigit(s[i])){
//                 isDigit = true;
//                 int digit = s[i] - '0';
//                 if((number > INT_MAX/10) || ( number == INT_MAX/10 && digit > 7 )) {
//                     if(signOfInteger == -1){
//                         return INT_MIN;
//                     }
//                     return INT_MAX;

//                 }
//                 number = number*10 + digit;
//             }
//         }
//         if(signOfInteger) return signOfInteger*number;
//         return number;
//     }
    
// };

// 0 ms time
// class Solution {
// public:
//     int myAtoi(string s) {
//         if(!s.length()) return 0;
//         long long res = 0;//we use long long, avoid integer overflowing
//         int i = 0;
//         bool isNeg = false;
        
//         while(isspace(s[i]))//ignore all leading whitespaces
//         {
//             ++i;
//         }
        
//         if(s[i] == '-')
//         {
//             isNeg = true;
//             ++i;
//         }else if(s[i] == '+'){
//             ++i;
//         }
        
//         while(i < s.length() && isdigit(s[i]))
//         {
//             res *= 10;
//             res += s[i] - 48;
//             if(res > INT_MAX)
//             {
//                 //if res > INT_MAX, then there could be integer
//                 //overflowing with type int, so we should return INT_MIN
//                 //or INT_MAX depending on isNeg
//                 return isNeg?INT_MIN:INT_MAX;
//             }
//             ++i;
//         }
//         return isNeg?-res:res;
//     }
// };

int myAtoi(string str) {
    long long int result = 0;
    int indicator = 1;
    if(str.empty()) return 0;
    int i = str.find_first_not_of(' ');
    if(i==-1) return 0;
    if(str[i] == '-' || str[i] == '+')
        indicator = (str[i++] == '-')? -1 : 1;
        
    while('0'<= str[i] && str[i] <= '9') 
    {
        result = result*10 + (str[i++]-'0');
        if(result*indicator >= INT_MAX) return INT_MAX;
        if(result*indicator <= INT_MIN) return INT_MIN;                
    }
        
    return result*indicator;
    }
};