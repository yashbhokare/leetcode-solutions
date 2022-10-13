class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> s_t_map;
        unordered_map<char,char> t_s_map;
        for(int i=0;i<s.size();i++){
            if(s_t_map.find(s[i])!=s_t_map.end() && s_t_map[s[i]]!=t[i]) return false;
            if(t_s_map.find(t[i])!=t_s_map.end() && t_s_map[t[i]]!=s[i]) return false;
            s_t_map[s[i]] = t[i];
            t_s_map[t[i]] = s[i];
        }
        return true;
    }
};