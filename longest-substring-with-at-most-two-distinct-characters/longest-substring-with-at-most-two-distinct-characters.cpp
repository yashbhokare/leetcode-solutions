class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> umap;
        int n =s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        while(right<n){
            char currC = s[right];
            umap[currC]++;
            while(umap.size()>2 && left<n){
                char tempC = s[left];
                umap[tempC]--;
                if(umap[tempC]==0) umap.erase(tempC);
                left++;
            }
            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
        
    }
};