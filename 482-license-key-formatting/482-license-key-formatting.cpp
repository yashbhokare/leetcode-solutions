class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        string formatS = "";
        
        for(auto ch:s){
            if(ch=='-') continue;
            formatS+=toupper(ch);
        }
        
        int count=0;
        
        reverse(formatS.begin(),formatS.end());
        
        for(int i=0;i<formatS.size();i++){
            if(count==k){
                result.push_back('-');
                count=0;
            }
           result.push_back(formatS[i]);
           count++;
        }
        reverse(result.begin(),result.end());
        return result;
    }

};