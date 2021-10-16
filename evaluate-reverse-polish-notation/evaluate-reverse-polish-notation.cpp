class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> tokenStack;
        for(string token: tokens){
            string cal = "";
            if(token == "+" || token == "-" || token =="*" || token =="/"){
                string val2 = tokenStack.top();
                tokenStack.pop();
                string val1 = tokenStack.top();
                tokenStack.pop();
                if(token == "+"){
                    cal = to_string(stoi(val1) + stoi(val2));
                }else if(token == "*"){
                   cal = to_string(stoi(val1) * stoi(val2));
                }else if(token == "/"){
                    cal = to_string(stoi(val1) / stoi(val2));
                }else {
                    cal = to_string(stoi(val1) - stoi(val2));
                }
                tokenStack.push(cal);
            }else {
                tokenStack.push(token);
            }
        }
        return stoi(tokenStack.top());
    }
};