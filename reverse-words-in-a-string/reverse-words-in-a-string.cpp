class Solution {
public:
    string reverseWords(string s) {
        stack<string> stack;
        int index=0;
        string result="";
        while(index<s.length()){
            // cout<<index<<" ";
            if(s[index]==' '){
                index++;
                continue;
            }
            string word="";
            while(index<s.length() && s[index]!=' '){
                // cout<<index<<" ";
                word+=s[index];
                index++;
            }
            stack.push(word);
        }
        while(!stack.empty()){
            // cout<<stack.top()<<endl;
            result+=stack.top();
            stack.pop();
            if(!stack.empty()){
                result+=' ';
            }   
        }
        return result;
    }
};