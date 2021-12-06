class Solution {
public:
   int lengthOfLongestSubstringTwoDistinct(string str) {
        int ans=0; 
        unordered_map<char,int> count;
        int l=0, r=0, N=str.length();
        while (r<N) {
          count[str[r]]++;
          while (count.size()>2 && r>=l) {
            count[str[l]]--;      
            if (count[str[l]]==0)
                count.erase(str[l]);
            l++;
          }  
          ans=max(ans,r-l+1);  
          r++;
        }
        return ans;
    }
};