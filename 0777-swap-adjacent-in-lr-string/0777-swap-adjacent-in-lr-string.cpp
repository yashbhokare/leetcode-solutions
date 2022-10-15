class Solution {
public:
    bool canTransform(string start, string end) {
        string s1="",s2="";
        for(auto c:start) if(c!='X') s1.push_back(c);
        for(auto c:end) if(c!='X') s2.push_back(c);
        if(s1!=s2) return false;
        
        int i=0,j=0;
        
        int m = start.size();
        int n = end.size();
        while(i<m || j<n){
            while(i<m && start[i]=='X') i++;
            while(j<n && end[j]=='X') j++;
            // if(i==m && j==n) return true;
            if(start[i]!=end[j]) return false;
            if(start[i]=='L' && j>i) return false;
            if(start[i]=='R' && j<i) return false;
            i++;
            j++;
        }
        return true;
    }
};