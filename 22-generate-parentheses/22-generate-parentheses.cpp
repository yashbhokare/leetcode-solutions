class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        rec("",0,0,n);
        return ans;
    }
    
    void rec(string s,int open,int close,int n){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n) rec(s+'(',open+1,close,n);
        if(close<open) rec(s+')',open,close+1,n);
    }
};