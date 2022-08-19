class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int startIndex = 0;
        string result = "";
        for(int i=0;i<s.size();i++){
            int len1 = expandMiddle(s,i,i);
            int len2 = expandMiddle(s,i,i+1);
            int len = max(len1,len2);
            if(len>maxLen){
                maxLen = len;
                startIndex = i-((len+1)/2)+1;
                 // startIndex = i -(len-1)/2;
            }
        }
        return s.substr(startIndex,maxLen);
    }
    
    int expandMiddle(string s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};