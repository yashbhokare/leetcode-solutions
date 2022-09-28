class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        vector<int> chars(26,0);
        for(int i=0;i<s.size();i++){
            chars[s[i]-'a']++;
            chars[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(chars[i]!=0) return false;
        }
        return true;
    }
};