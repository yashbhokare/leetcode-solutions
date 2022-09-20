class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> targetMap;
        for(auto ch:t) targetMap[ch]++;
        int count = targetMap.size();
        int left=0;
        int right=0;
        int minIndex = 0;
        int minLength = INT_MAX;
        
        unordered_map<char,int> currMap;
        while(right<s.size()){
            char right_char = s[right];
            if(targetMap.find(right_char)!=targetMap.end()){
                currMap[right_char]++;
                if(currMap[right_char]==targetMap[right_char]) count--;
            }
            
            while(count==0){
                int distance = right-left+1;
                if(distance<minLength){
                    minIndex = left;
                    minLength= distance;
                }
                char left_char = s[left];
                if(targetMap.find(left_char)!=targetMap.end()){
                    currMap[left_char]--;
                    if(currMap[left_char]<targetMap[left_char]) count++;
                }
                left++;
            }
            right++;
        }
        if(minLength==INT_MAX) return "";
        return s.substr(minIndex,minLength);
    }
};