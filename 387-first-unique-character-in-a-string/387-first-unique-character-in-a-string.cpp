class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charSet(26,-1);
        for(int i=0;i<s.size();i++){
            charSet[s[i]-'a']++;
        }
        
        for(int i=0;i<s.size();i++){
            if(charSet[s[i]-'a']==0) return i;
        }
        return -1;
    }
};