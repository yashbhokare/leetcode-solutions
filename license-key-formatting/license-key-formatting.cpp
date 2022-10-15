class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string formatS = "";
        
        for(auto ch:s){
            if(ch=='-') continue;
            else{
                if(ch>96) ch-=32; //transform to upper (ASCII ->'a'=97,'A'=65)
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
    // string licenseKeyFormatting(string s, int k) {
    //     string result = "";
    //     int count = 0;
    //     for(int i=s.size()-1;i>=0;i--){
    //         if(s[i]=='-') continue;
    //         if(count==k){
    //             count=0;
    //             result.insert(result.begin(),'-');
    //         }
    //        result.insert(result.begin(),toupper(s[i]));
    //         count++;
    //     }
    //     return result;
    // }

};