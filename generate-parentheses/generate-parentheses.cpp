class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        rec(n,0,0,"");
        return result;
    }
    
    void rec(int n,int open,int close,string s){
        if(s.size()==2*n){
            result.push_back(s);
        }
        if(open<n) rec(n,open+1,close,s+"(");
        if(close<open) rec(n,open,close+1,s+")");
    }
};