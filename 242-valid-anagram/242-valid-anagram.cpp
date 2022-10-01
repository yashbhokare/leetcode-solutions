class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n = s.size();
        vector<int> char_count(26,0);
        for(int i=0;i<n;i++){
            char_count[s[i]-'a']++;
            char_count[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(char_count[i]!=0) return false;
        }
        return true;
    }
};