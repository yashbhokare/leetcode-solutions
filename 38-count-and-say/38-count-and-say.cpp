class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i=2;i<=n;i++){
            int count = 1;
            string ans ="";
            int j=1;
            for(j=1;j<res.size();j++){
                if(res[j]==res[j-1]){
                    count++;
                }else {
                    ans = ans +  to_string(count)+ res[j-1];
                     count = 1;
                }
            }
            ans = ans +  to_string(count)+ res[j-1];
            // cout<<ans<<endl; 
            res = ans;
        }
        return res;
    }
};