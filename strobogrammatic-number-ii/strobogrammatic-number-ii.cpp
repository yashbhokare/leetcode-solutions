class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return rec(n,n);
    }
    
    vector<string> rec(int n,int m){
        if(m==0) return {""};
        if(m==1) return {"0","1","8"};
        vector<string> res;
        vector<string> data = rec(n,m-2);
        for(int i=0;i<data.size();i++){
            if(m!=n) res.push_back("0"+data[i]+"0");
            res.push_back("1"+data[i]+"1");
            res.push_back("6"+data[i]+"9");
            res.push_back("8"+data[i]+"8");
            res.push_back("9"+data[i]+"6");
        }
        return res;
    }
};