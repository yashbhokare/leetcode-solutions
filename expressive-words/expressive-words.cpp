class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        for(auto word:words){
            if(isExpressive(s,word)){
                count++;
            }
        }
        return count;
    }
    
    
    bool isExpressive(string source,string dstn){
        int i=0,j=0;
        int sCount = 0,dCount = 0;
        int n = source.size(),m=dstn.size();
        while(i<n && j< m){
            sCount = 1;
            dCount = 1;
            if(source[i]!=dstn[j]) return false;
            while(i<n && source[i]==source[++i]) sCount++;
            while(j<m && dstn[j]==dstn[++j]) dCount++;
            if(sCount==dCount) continue;
            if(dCount > sCount) return false;
            if(sCount<3) return false;
        }
        return (i==n && j==m);
    }
};