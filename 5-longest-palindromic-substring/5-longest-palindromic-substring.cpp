class Solution {
public:
    string longestPalindrome(string s) {
        int maxString=0;
        int startIndex = 0;
        for(int i=0;i<s.size();i++){
            int len1=expandFromMiddle(i,i,s);
            int len2=expandFromMiddle(i,i+1,s);
            int maxLen = max(len1,len2);
            cout<<maxLen<<endl;
            if(maxLen > maxString){
                maxString = maxLen;
                startIndex = i -(maxLen-1)/2;
            }
        }
        return s.substr(startIndex,maxString);
    }
    
    int expandFromMiddle(int left,int right,string s){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};