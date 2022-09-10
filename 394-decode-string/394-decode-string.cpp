class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string decodedOne = "";
                while(stk.top()!="["){
                    decodedOne= stk.top()+decodedOne;
                    stk.pop();
                }
                stk.pop(); // Remove the [ from stack
                string sdigit = "";
                while(!stk.empty() && stk.top()>="0" && stk.top()<="9" ){
                    sdigit = stk.top() + sdigit;
                    stk.pop();
                }
                int digit = stoi(sdigit);
                while(digit--){
                    stk.push(decodedOne);
                }
            }else {
                string str ="";
                str.push_back(s[i]);
                
                // cout<<str;
                stk.push(str);
            }
        }
        string result = "";
        while(!stk.empty()){
            result = stk.top()+result;
            stk.pop();
        }
        return result;
    }
};