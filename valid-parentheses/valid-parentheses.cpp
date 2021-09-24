class Solution {
public:
    bool isValid(string s) {
        vector<char> stack = {};
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                stack.push_back(s[i]);
                continue;
            } 
            if((s[i]==')' || s[i]=='}' || s[i]==']') && !stack.empty()) {
                if(s[i]== ')' && stack.back() == '('){
                    stack.pop_back();
                    continue;
                } else if(s[i]== ']' && stack.back() == '['){
                    stack.pop_back();
                    continue;
                } else if(s[i]== '}' && stack.back() == '{'){
                    stack.pop_back();
                    continue;
                } else {
                    return false;
                }
            }
            if(stack.empty()) return false;
        }
        if(stack.empty()) return true;
        return false;
    }
};