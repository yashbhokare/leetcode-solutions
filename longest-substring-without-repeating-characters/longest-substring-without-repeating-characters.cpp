class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int startPos = 0;
        int startingIndex = 0;
        unordered_map<char,int> mapper;
        for(int i =0;i<s.size();i++){
            auto it = mapper.find(s[i]);

            if(it != mapper.end()){
                startPos = max(startPos,mapper[s[i]]+1);
                mapper.erase(s[i]);
            }
            
            if(i-startPos + 1 > maxLen){
                maxLen = i - startPos +1;
                startingIndex = startPos;
            }
            mapper.insert({s[i],i});
            
        }
        cout<<s.substr(startingIndex,maxLen);
        return maxLen;
    }
};