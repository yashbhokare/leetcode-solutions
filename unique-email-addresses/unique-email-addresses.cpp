class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for(string email:emails){
            int indexforDomain = email.find_first_of('@');
            string domain = email.substr(indexforDomain);
            string localName = email.substr(0,indexforDomain);
            string filteredLocalName = "";
            for(char ch:localName){
                if(ch=='+') break;
                if(ch=='.') continue;
                filteredLocalName+=ch;
            }
            string result = filteredLocalName + domain;
            set.insert(result);
        }
        return set.size();
    }
};