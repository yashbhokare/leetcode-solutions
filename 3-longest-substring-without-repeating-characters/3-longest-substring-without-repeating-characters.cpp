class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mapper;
        int left = 0;
        int  longestString = 0;
        for(int right=0;right<s.size();right++){
            if(mapper.find(s[right])!=mapper.end()){
                left=max(left,mapper[s[right]]+1);
            }
            longestString = max(longestString,right-left+1);
            mapper[s[right]]=right;
            
        }
        return longestString;
    }
};