class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int n=s.length();
        int result=0;
        unordered_map<char,int> mapper;
        while(right<n){
            if(mapper.find(s[right])!=mapper.end()){
                left=max(mapper[s[right]]+1,left);
            }
            result=max(result,right-left+1);
            mapper[s[right]]=right;
            right++;
        }
        return result;
    }
};