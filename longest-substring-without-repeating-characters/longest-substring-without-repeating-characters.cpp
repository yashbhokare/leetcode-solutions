class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int startIndex =0;
        int maxLength = 0;
        int startPos;
        unordered_map<char,int> mapper;
        for(int i=0;i<s.length();i++){
            auto it = mapper.find(s[i]);
            // char found
            if(it != mapper.end()){
                startIndex = max(startIndex,it->second + 1);
                mapper.erase(s[i]);
            }
            mapper.insert({s[i],i});
            if((i-startIndex +1)>maxLength){
                maxLength = i-startIndex +1;
                startPos = startIndex;
            }
            
        }
        cout<<startPos;
        cout<<maxLength;
        
        return maxLength;
    }
};