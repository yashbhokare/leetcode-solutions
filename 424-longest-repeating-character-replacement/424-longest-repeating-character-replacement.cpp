class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mapper;
        int left=0;
        int max_freq = 0;
        int result=0;
        for(int right=0;right<s.size();right++){
            mapper[s[right]]++;
            max_freq = max(max_freq,mapper[s[right]]);
            
            int letters_to_replace = (right-left+1)-max_freq;
            if(letters_to_replace>k){
                mapper[s[left]]--;
                left++;
                // max_freq = 0;
            }
            result = max(result,right-left+1);
            
        }
        return result;
    }
};