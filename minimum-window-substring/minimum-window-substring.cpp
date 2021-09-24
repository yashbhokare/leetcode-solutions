class Solution {
public:
string minWindow(string s, string t) {
        vector<int> hist(128, 0);
        for (char c : t) hist[c]++;
        
        int remaining = t.length();
        int left = 0, right = 0, minStart = 0, minLen = INT_MAX;
        while (right < s.length()){
            if (--hist[s[right++]] >= 0) {
                remaining--;
            }
            while (remaining == 0){
                if (right - left < minLen){
                    minLen = right - left;
                    minStart = left;
                }
                if (++hist[s[left++]] > 0) remaining++;
            }
        }
            
         return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
        }
};