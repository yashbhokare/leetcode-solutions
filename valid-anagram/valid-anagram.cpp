class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_multiset<char> stringSet;
        for(int i =0;i<s.length();i++){
            stringSet.insert(s[i]);
        }
        
        for(int i =0;i<t.length();i++){
            auto it = stringSet.find(t[i]);
            if(it == stringSet.end()){
                return false;
            } else {
                stringSet.erase(it);
            }
        }
        if(stringSet.empty()) return true;
        return false;;
    }
};