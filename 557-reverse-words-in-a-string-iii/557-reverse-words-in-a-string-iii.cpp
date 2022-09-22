class Solution {
public:
    string reverseWords(string s) {
        string result="";
        stringstream ss(s);
        string word;
        while(ss>>word){
            reverse(word.begin(),word.end());
            result=result+" "+word;
        }
        return result.substr(1);
    }
};