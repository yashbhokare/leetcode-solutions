class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<=right){
            if(!isalnum(s[left])) {
                // cout<<s[left];
                left++;
                continue;
            }
            if(!isalnum(s[right])) {
                // cout<<s[right];
                right--;
                continue;
            }
            if(tolower(s[left])==tolower(s[right])){
                left++;
                right--;
            }else {
                return false;
            }

        }
        return true;
    }
};