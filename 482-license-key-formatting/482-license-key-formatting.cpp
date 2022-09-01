class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int index = s.size()-1;
        int count=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='-') continue;
            if(count==k){
                result.push_back('-');
                count=0;
            }
           result.push_back(toupper(s[i]));
           count++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};