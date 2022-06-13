class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> totalChars(26,0);
        for(int i=0;i<s.size();i++){
            totalChars[s[i]-'a']++;
            totalChars[t[i]-'a']--;
        }
        
        for(auto count:totalChars){
            if(count!=0) return false;
        }
        return true;
    }
};