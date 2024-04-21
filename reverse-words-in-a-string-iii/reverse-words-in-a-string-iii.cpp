class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        int right=0;
        int n=s.length();
        int index=0;
        while(index<n){
            while(index<n && s[index]!=' '){
                index++;
            }
            // if(index==n) break;
            reverse(s.begin()+left,s.begin()+index);
            index++;
            left=index;
        }
        return s;
    }
};