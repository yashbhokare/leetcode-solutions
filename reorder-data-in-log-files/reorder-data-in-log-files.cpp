class Solution {

public:
    static int comparator(const string& string1,const string& string2) {
        auto substr1 = string1.substr(string1.find_first_of(' ')+1);
        auto substr2 = string2.substr(string2.find_first_of(' ')+1);
        if(substr1 == substr2) {
            return string1 < string2;
        }
        return substr1 < substr2;
        }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> stringVal;
        vector<string> digits;
        for(int i=0;i<logs.size();i++){
            if(isalpha(logs[i][logs[i].find_first_of(' ')+1])){
                stringVal.push_back(logs[i]);
            }else {
                digits.push_back(logs[i]);
            }
        }
        sort(stringVal.begin(),stringVal.end(),comparator);
        for(string dig:digits) stringVal.push_back(dig);
        return stringVal;
    }
};
