class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string formatS = "";
        
        for(auto ch:s){
            if(ch=='-') continue;
            else{
                if(ch>96) ch-=32;
                formatS+=ch;
            }
        }
        
        int count=0;
        s = "";
        reverse(formatS.begin(),formatS.end());
        
        for(int i=0;i<formatS.size();i++){
            if(count==k){
                s.push_back('-');
                count=0;
            }
           s.push_back(formatS[i]);
           count++;
        }
        reverse(s.begin(),s.end());
        return s;
    }

};