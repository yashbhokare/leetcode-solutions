class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int result = 0;
        unordered_map<char,int> mapper;
        for(int right=0;right<s.size();right++){
            char ch = s[right];
            if(mapper.find(ch)!=mapper.end()){
                left = max(left,mapper[ch]+1);
            }
            result= max(result,right-left+1);
            mapper[ch]=right;
            
            
        }
        return result;
    }
};