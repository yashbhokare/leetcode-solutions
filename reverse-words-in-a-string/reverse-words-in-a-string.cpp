class Solution {
public:
    string reverseWords(string s){
        reverse(s.begin(),s.end());
        int head=0;
        int index=0;
        int n=s.length();
        while(true){
            while(index<n && s[index]==' '){
                index++;
            }
            if(index==n) break;
            int pos=head;
            while(index<n && s[index]!=' '){
                s[pos++]=s[index++];
            }
            reverse(s.begin()+head,s.begin()+pos);
            s[pos++]=' ';
            head=pos;
        }
        s.resize(head-1);
        return s;
    }
    
    // string reverseWords(string s){
    //     stringstream ss(s);
    //     string word, ans;
    //     while(ss >> word){
    //         ans = word + " " + ans;
    //     }
    //     return ans.substr(0, ans.size()-1);;     
    // }
};
// class Solution {
// public:
//     string reverseWords(string s) {
//         stack<string> stack;
//         int index=0;
//         string result="";
//         while(index<s.length()){
//             if(s[index]==' '){
//                 index++;
//                 continue;
//             }
//             string word="";
//             while(index<s.length() && s[index]!=' '){
//                 word+=s[index];
//                 index++;
//             }
//             stack.push(word);
//         }
//         while(!stack.empty()){
//             result+=stack.top();
//             stack.pop();
//             if(!stack.empty()){
//                 result+=' ';
//             }   
//         }
//         return result;
//     }
// };