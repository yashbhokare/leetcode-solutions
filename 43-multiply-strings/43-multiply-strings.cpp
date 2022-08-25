class Solution {
public:
    string multiply(string num1, string num2) {
        // vector<int> result(num1.size()+num2.size(),0);
        int n1Max = num1.size()-1;
        int n2Max = num2.size()-1;
        string result = "";
        for(int i=n1Max,m=0;i>=0;i--,m++){
            string val = "";
            int carry = 0;
            for(int h=0;h<m;h++){
                val = val + "0";
            }
            for(int j=n2Max;j>=0;j--){
                int cal = (num1[i]-'0')*(num2[j]-'0') + carry;
                val = val + to_string(cal%10);
                carry = cal/10;
            }
            if(carry>0)
                val = val + to_string(carry);
            result =addString(result,val);
        }
        reverse(result.begin(),result.end());
        int zeroIndex = result.find_first_not_of('0');
        if(zeroIndex==-1) return "0";
        result = result.substr(zeroIndex);
        return result;
    }
    
    string addString(string s1,string s2){
        if(s1=="") return s2;
        int carry = 0;
        string result = "";
        for(int i=0;i<s1.size() || i<s2.size();i++){
            int val1 = i<s1.size() ? s1[i]-'0' : 0;
            int val2 = i<s2.size() ? s2[i]-'0' : 0;
            int val =val1+val2+carry;
            result = result + to_string(val%10);
            carry = val/10;
        }
        if(carry!=0){
            result = result + to_string(carry);
        }
        return result;
    }
};