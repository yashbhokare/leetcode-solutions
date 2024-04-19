class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length()-1;
        int n = b.length()-1;
        int carry=0;
        string result="";
        while(m>=0 || n>=0 || carry){
            if(m>=0){
               carry+=a[m--]-'0';
            }
            if(n>=0){
               carry+=b[n--]-'0';
            }
            char val=carry%2+'0';
            result= val +result;
            carry=carry/2;
        }
        return result;
    }
};