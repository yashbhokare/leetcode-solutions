class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mapper;
        int result = 0;
        for(auto c:s){
            mapper[c]++;
        }
        
        bool isOdd = false;
        for(auto it=mapper.begin();it!=mapper.end();it++){
            
            int total = it->second;
            if(!isOdd && total%2!=0) isOdd=true;
            result = result + total/2*2;
        }
        if(isOdd) result++;
        return result;
    }
};