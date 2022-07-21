class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for(auto email:emails){
            int domainIndex = email.find_first_of('@');
            string domain = email.substr(domainIndex);
            string localName = email.substr(0,domainIndex);
            string formattedLocalName = formatLocalName(localName);
            set.insert(formattedLocalName+domain);
        }
        return set.size();
    }
    
    string formatLocalName(string localName){
        string newLocalName = "";
        for(auto c:localName){
            if(c=='+') return newLocalName;
            if(c=='.') continue;
            newLocalName+=c;
        }
        return newLocalName;
    }
};