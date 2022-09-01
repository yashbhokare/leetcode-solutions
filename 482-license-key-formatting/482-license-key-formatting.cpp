class Solution {
public:
//     string licenseKeyFormatting(string s, int k) {
//         string formatS = "";
        
//         for(auto ch:s){
//             if(ch=='-') continue;
//             else{
//                 if(ch>96) ch-=32;
//                 formatS+=ch;
//             }
//         }
        
//         int count=0;
//         s = "";
//         reverse(formatS.begin(),formatS.end());
        
//         for(int i=0;i<formatS.size();i++){
//             if(count==k){
//                 s.push_back('-');
//                 count=0;
//             }
//            s.push_back(formatS[i]);
//            count++;
//         }
//         reverse(s.begin(),s.end());
//         return s;
//     }
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