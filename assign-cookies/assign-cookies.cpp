class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0) return 0;
        int gPos = 0;
        int sPos=0;
        int ans = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(gPos < g.size() && sPos < s.size()){
            if(g[gPos] <= s[sPos]){
                gPos++;
                cout<<gPos<<endl;
            }
            sPos++;
        }
        return gPos;
    }
};