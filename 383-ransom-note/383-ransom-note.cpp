class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size()<ransomNote.size()) return false;
        vector<int> charArray(26,0);
        for(auto letter:magazine){
            charArray[letter-'a']++;
        }
        
        for(auto letter:ransomNote){
            charArray[letter-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(charArray[i]<0) return false;
        }
        return true;
    }
};