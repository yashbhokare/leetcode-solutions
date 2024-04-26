class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        unordered_map<char,char> mapperstot;
        unordered_map<char,char> mapperttos;// mapper t -> s
        
        for(int i=0;i<s.length();i++){
            if(mapperstot.count(s[i])>0 && mapperstot[s[i]]!=t[i]){
                return false;
            }else if(mapperttos.count(t[i])>0 && mapperttos[t[i]]!=s[i]) {
                return false;
            }else {
                mapperstot[s[i]]=t[i];
                mapperttos[t[i]] =s[i];
            }
        }
    
        return true;
    }
};