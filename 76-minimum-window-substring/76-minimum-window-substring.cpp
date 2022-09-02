class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> targetMapper;
        unordered_map<char,int> currMapper;
        int left=0,right=0;
        int n = s.size();
        int minLen = INT_MAX;
        int startIndex = -1;
        int tMapSize = 0;
        
        if(t.size()==0) return "";
        
        for(auto c:t){
            targetMapper[c]++;
        }
        
        tMapSize = targetMapper.size();
        
        while(right<n){
            
            char curr = s[right];
            if(targetMapper.find(curr)!=targetMapper.end()){
                currMapper[curr]++;
                if(currMapper[curr]==targetMapper[curr]) tMapSize--;
            }
            while(tMapSize==0){
                
                if(right-left+1<minLen){
                    minLen = right-left+1;
                    startIndex = left;
                }
                char leftCurr = s[left];
                if(currMapper.find(leftCurr)!=currMapper.end()){
                    currMapper[leftCurr]--;
                    if(currMapper[leftCurr]<targetMapper[leftCurr]) tMapSize++;
                }
                left++;
            }
            right++;
        }
        if(startIndex==-1) return "";
        
        return s.substr(startIndex,minLen);
        
        
    }
};

// For more optimization use a filtered string filtered_S

 // S = "ABCDDDDDDEEAFFBC" T = "ABC"
 //   filtered_S = [(0, 'A'), (1, 'B'), (2, 'C'), (11, 'A'), (14, 'B'), (15, 'C')]
 //  Here (0, 'A') means in string S character A is at index 0.