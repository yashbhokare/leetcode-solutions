class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c==')' || c==']' || c=='}'){
                if(stk.empty()) return false;
                if((c==')' && stk.top()=='(') || (c==']' && stk.top()=='[') || (c=='}' && stk.top()=='{') ){
                    stk.pop();
                    continue;
                }else{
                    return false;
                }
            } 

            cout<<c;
            stk.push(c);
        }
        
        return stk.empty();
    }
};