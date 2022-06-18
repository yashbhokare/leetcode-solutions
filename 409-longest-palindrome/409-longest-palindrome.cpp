class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mapper;
        int result = 0;
        for(auto c:s){
            mapper[c]++;
            if(mapper[c]==2){
                result+=2;
                mapper.erase(c);
            }
        }
        if(mapper.size()>0) result++;
        return result;
    }
};