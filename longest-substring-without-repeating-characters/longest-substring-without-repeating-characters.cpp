class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLen = 0;
        unordered_map<char,int> mapper;
        int left = 0;
        for(int right=0;right<s.size();right++){
            if(mapper.find(s[right])!=mapper.end()){
                left = max(mapper[s[right]]+1,left);
            }
            longestLen= max(longestLen,right-left+1);
            mapper[s[right]] = right;
            
        }
        return longestLen;
    }
};