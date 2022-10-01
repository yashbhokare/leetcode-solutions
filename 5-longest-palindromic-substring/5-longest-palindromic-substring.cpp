class Solution {
public:
    string longestPalindrome(string s) {
        int max_length = 0;
        int start_index=0;
        for(int i=0;i<s.size();i++){
            int len1 = expandFromMiddle(i,i,s);
            int len2 = expandFromMiddle(i,i+1,s);
            int maxLen = max(len1,len2);
            if(maxLen>max_length){
                max_length = maxLen;
                start_index = i-(maxLen-1)/2;
            }
        }
        return s.substr(start_index,max_length);
    }
    
    int expandFromMiddle(int left,int right,string s){
        int n = s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};