class Solution {
public:
    string longestPalindrome(string s) {
        return expandingFromMiddle(s);
    }
    
    string expandingFromMiddle(string s){
        string result = "";
        for(int i=0;i<s.size();i++){
            string s1 = expandFromMiddle(i,i,s);
            string s2 = expandFromMiddle(i,i+1,s);
            if(s1.size() > s2.size() && s1.size() > result.size()){
                result = s1;
            }else if(s2.size() > result.size()){
                result=s2;
            }
        }
        return result;
    }
    
    string expandFromMiddle(int left,int right,string s){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
        // return right-left-1;
    }
};