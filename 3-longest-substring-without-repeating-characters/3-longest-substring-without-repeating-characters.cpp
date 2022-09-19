//Time complexity : O(n)
//Space complexity : O(n) where it can be maximum to n if all chars are different

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mapper;
        int longest = 0;
        int left=0;
        for(int right=0;right<s.size();right++){
            if(mapper.find(s[right])!=mapper.end()){
                left = max(left,mapper[s[right]]+1);
            }
            longest = max(longest,right-left+1);
            mapper[s[right]]=right;
        }
        return longest;
    }
};