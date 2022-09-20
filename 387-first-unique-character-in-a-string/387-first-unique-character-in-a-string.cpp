class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charArray (26,0);
        for(auto ch:s) charArray[ch-'a']++;
        for(int i=0;i<s.size();i++){
            if(charArray[s[i]-'a']==1) return i; 
        }
        return -1;
    }
};