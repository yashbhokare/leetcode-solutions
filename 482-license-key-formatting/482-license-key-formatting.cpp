class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int count = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='-') continue;
            if(count==k){
                count=0;
                result.insert(result.begin(),'-');
            }
           result.insert(result.begin(),toupper(s[i]));
            count++;
        }
        return result;
    }
};