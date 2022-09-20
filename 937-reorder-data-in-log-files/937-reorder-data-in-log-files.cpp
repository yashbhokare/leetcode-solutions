class Solution {
public:
    static bool comparator(string& s1,string& s2){
        int s1_index = s1.find_first_of(' ');
        int s2_index = s2.find_first_of(' ');
        string id1 = s1.substr(0,s1_index);
        string id2 = s2.substr(0,s2_index);
        
        string content1 = s1.substr(s1_index+1);
        string content2 = s2.substr(s2_index+1);
        if(content1!=content2) return content1 < content2;
        return id1 < id2;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs;
        vector<string> digitLogs;
        for(auto log:logs){
            int index = log.find_first_of(' ');
            index++;
            if(isalpha(log[index])){
                letterLogs.push_back(log);
            }else {
                digitLogs.push_back(log);
            }
        }
        
        sort(letterLogs.begin(),letterLogs.end(),comparator);
        for(auto digLogs:digitLogs){
            letterLogs.push_back(digLogs);
        }
        return letterLogs;
    }
};