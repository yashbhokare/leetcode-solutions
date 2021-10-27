class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int count = 0;
        unordered_set <string> set;
        for(int i=0;i<emails.size();i++){
            int signIndex = emails[i].find_first_of('@');
            if(signIndex == -1) continue;
            string localName = emails[i].substr(0,signIndex);
            string domainName = emails[i].substr(signIndex);
            string resultLocalName = "";
            for(int j=0;j<localName.size();j++){
                if(localName[j]=='+') break;
                if(localName[j]=='.') continue;
                resultLocalName +=localName[j];
            }
            set.insert(resultLocalName+domainName);
            
        }
        return set.size();
    }
};