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
// Better Solution as compared to run time
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length()) return false;
//         int n = s.length();
//         int counts[26] = {0};
//         for (int i = 0; i < n; i++) { 
//             counts[s[i] - 'a']++;
//             counts[t[i] - 'a']--;
//         }
//         for (int i = 0; i < 26; i++)
//             if (counts[i]) return false;
//         return true;
//     }
// };