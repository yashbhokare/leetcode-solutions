class Solution {
public:
    string countAndSay(int n) {
        return countAndSayCal(n);
    }
    string countAndSayCal(int n){
        if(n==1){
            return "1";
        }
        string val = countAndSayCal(n-1);
        string result = "";
        int count = 1;
        int i=0;
        for(i=0;i<val.length()-1;i++){
            if(val[i]!=val[i+1]){
                result = result + to_string(count) + val[i]; 
                count = 0;
            }
            count++;
        }
        // cout<<
        result = result + to_string(count) + val[i]; 
        return result;
    }
};