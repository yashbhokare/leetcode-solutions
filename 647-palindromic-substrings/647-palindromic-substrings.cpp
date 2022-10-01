class Solution {
public:
    int countSubstrings(string s) {
        int total = s.size();
        for(int i=0;i<s.size();i++){
            int len1 = expandFromMiddle(i,i,s);
            int len2 = expandFromMiddle(i,i+1,s);
            total+= len1/2 + len2/2;
        }
        return total;
        
    }
    
    int expandFromMiddle(int left,int right,string s){
        int n=s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};