class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto token:tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(token=="+") stk.push(a+b);
                else if(token=="-") stk.push(a-b);
                else if(token=="/") stk.push(a/b);
                else if(token=="*") stk.push(a*b);
            }else{
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};