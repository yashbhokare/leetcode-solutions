class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mapper;
        int left=0;
        int result=0;
        for(int right =0;right<s.size();right++){
            if(mapper.find(s[right])!=mapper.end()){
                left = max(left,mapper[s[right]]+1);   
            }
            result=max(result,right-left+1);
            mapper[s[right]]=right;
        }
        return result;
    }
};