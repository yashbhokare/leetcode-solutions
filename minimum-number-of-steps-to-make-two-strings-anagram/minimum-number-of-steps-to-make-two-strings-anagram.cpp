class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> charIndex(26,0);
        if(s.length()!=t.length()) return -1;
        for(int i=0;i<s.length();i++){
            charIndex[s[i]-'a']++;
            charIndex[t[i]-'a']--;
        }
        int result = 0;
        for(int i=0;i<26;i++){
            if(charIndex[i]>0)
            result = result + charIndex[i];
        }
        return result;
    }
};