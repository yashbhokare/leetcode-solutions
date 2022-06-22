class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> existingMapper;
        for(auto ch:t){
            existingMapper[ch]++;
        }
        
        int left=0;
        int right=0;
        string result = "";
        int min = INT_MAX;
        unordered_map<char,int> windowMapper;
        int windowSize = existingMapper.size();
        while(right<=s.size()-1){
            char ch = s[right];
            
            if(existingMapper.find(ch)!=existingMapper.end()){
                windowMapper[ch]++;
                if(windowMapper[ch]==existingMapper[ch]){
                    windowSize--;
                }
            }
            
            while(windowSize==0 && left<=right){
                char chLeft = s[left];
                if(existingMapper.find(chLeft)!=existingMapper.end()){
                    windowMapper[chLeft]--;
                    if(windowMapper[chLeft]<existingMapper[chLeft]){
                        windowSize++;
                    }
                }
                if(right-left+1 < min){
                    min = right-left+1;
                    result = s.substr(left,min);
                }
                left++;
            }
            
            right++;
            
        }
        return result;
    }
};