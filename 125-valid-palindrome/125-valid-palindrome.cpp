class Solution {
public:
    bool isPalindrome(string s) {
        int index=0;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                if(s[i]>='A' && s[i]<='Z'){
                    s[i]=s[i]-'A'+'a';
                }
                s[index++]=s[i];
            }
        }
        int left=0;
        int right=index-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};