class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        reverseTheString(num1);
        reverseTheString(num2);
        
        string result = "";
        string zeros = "";
        for(int n1=0;n1<num1.size();n1++){
            if(n1>0) zeros.push_back('0');
            int carry = 0;
            int val1 = num1[n1]-'0';
            string total = ""+zeros;
            
            for(int n2=0;n2<num2.size();n2++){
                int val2 = num2[n2] - '0';
                int mul = val1*val2+carry;
                total = total + to_string(mul%10);
                carry = mul/10;
            }
            if(carry) total = total + to_string(carry);
            result=additionOfStrings(result,total);
        }
        reverseTheString(result);
        return result;
    }
    
    void reverseTheString(string& s){
         reverse(s.begin(),s.end());
    }
    
    string additionOfStrings(string s1,string s2){
        string res = "";
        int maxSize = max(s1.size(),s2.size());
        int index = 0;
        int carry=0;
        while(index!=maxSize){
            int val1= index < s1.size() ? s1[index]-'0' : 0;
            int val2= index < s2.size() ? s2[index]-'0' : 0;
            int add = val1+val2+carry;
            res = res + to_string(add%10);
            carry = add/10;
            index++;
        }
        if(carry) res = res + to_string(carry);
        return res;
    }
};