class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stck;
        int result = 0;
        for(char c:s){
            if(c=='('){
                stck.push(c);
            }else if(!stck.empty()){
                stck.pop();
            }else {
                result++;
            }
        }
        return result + stck.size();
        
    }
};