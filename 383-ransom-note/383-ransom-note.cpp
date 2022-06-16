class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> totalChars(26,0);
        for(auto letter:ransomNote){
           totalChars[letter-'a']++;
        }
        for(auto letter:magazine){
            totalChars[letter-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(totalChars[i]>0) return false;
        }
        return true;
    }
};