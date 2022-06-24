class Solution {
public:
    string addBinary(string a, string b) {
        string carry = "0";
        string res = "";
        int i = a.size()-1;
        int j = b.size()-1;
        while(i>=0 || j>=0){
            
            if(i<0){
                i=0;
                a[i]='0';
            } 
            
            if(j<0){
                j=0;
                b[j]='0';
            } 
            if(a[i]=='1' && b[j]=='1' && carry=="1") {
                // cout<<"A"<<" ";
                 res = "1" + res;
                 carry = "1";
            }
            else if((a[i]=='1' && b[j]=='1') || ((a[i]=='1' || b[j]=='1') && carry=="1")){
                // cout<<"B"<<" ";
                res = "0" + res;
                carry = "1";
            }else{
                // cout<<"C"<<" ";
                int total = (a[i]-'0') + (b[j]-'0') + stoi(carry); 
                res= to_string(total) + res;
                carry="0";
            }
            i--;
            j--;
        }
        if(carry=="1") return  res = "1" + res;
        return res;
    }
};