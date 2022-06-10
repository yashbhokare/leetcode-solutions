class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        else if(isPalindrome(s)) return 1;
        else return 2; // A subsequence can mean deleting any chars so max we could delete a first then b  
    }
    
    bool isPalindrome(string s){
        int left=0;
        int right=s.size()-1;
        while(left<=right){
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
};