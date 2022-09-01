class Solution {
public:
    // string licenseKeyFormatting(string s, int k) {
    //     string result = "";
    //     int index = s.size()-1;
    //     int count=0;
    //     reverse(s.begin(),s.end());
    //     for(int i=0;i<s.size();i++){
    //         if(s[i]=='-') continue;
    //         if(count==k){
    //             result.push_back('-');
    //             count=0;
    //         }
    //        result.push_back(toupper(s[i]));
    //        count++;
    //     }
    //     reverse(result.begin(),result.end());
    //     return result;
    // }
    string licenseKeyFormatting(string s, int k) {
        string ss=""; //string without '-'
        for(auto c: s){
            if(c=='-'){}
            else{
                if(c>96) c-=32;  //transform to upper (ASCII ->'a'=97,'A'=65)
              ss+=c;  
            } 
        }
        s="";
        reverse(ss.begin(),ss.end());
        int cnt=0;
        for(auto c: ss)
        {
            if(cnt==k) {s.push_back('-'); cnt=0;}  // add '-'
            s.push_back(c);
            cnt++;
        }
        reverse(s.begin(),s.end()); //reverse the result.
        return s;
    }
};