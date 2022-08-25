class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> targetMapper;
        unordered_map<char,int> subStringMapper;
        
        for(auto ch:t) targetMapper[ch]++;
        
        int targetMapSize = targetMapper.size();
        
        int left=0;
        int right=0;
        int maxLen = s.size();
        int subStringMapSize = 0;
        int resultPos = 0;
        int resultSize = INT_MAX;
        while(right<maxLen){
              
            if(targetMapper.find(s[right])!=targetMapper.end()){
                subStringMapper[s[right]]++;
                if(subStringMapper[s[right]]==targetMapper[s[right]]){
                    subStringMapSize++;
                }
            }
            
            while(subStringMapSize==targetMapSize && left<maxLen){
                if(right-left+1<resultSize){
                    resultSize = right-left+1;
                    resultPos = left;
                }
                
                if(targetMapper.find(s[left])!=targetMapper.end()){
                    subStringMapper[s[left]]--;
                    if(subStringMapper[s[left]]<targetMapper[s[left]]){
                        subStringMapSize--;
                    }
                }
                left++;
            }
            right++;
        }
        if(resultSize==INT_MAX) return "";
        return s.substr(resultPos,resultSize);
    }
};