class Solution {

public:
    static int comparator(string& string1,string& string2) {
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


// class Solution {
// public:
//     vector<string> reorderLogFiles(vector<string>& logs) {
//         // We can break this problem into two tasks: 1) Parition 2) Sort letter-logs

//         // Partition: letter-logs at the front, digit-logs at the back.
//         // We're using stable_partition instead of partition to retain the original order.
//         // stable_partition returns an iterator to the first element of the second group.
        
//         auto it = stable_partition(logs.begin(), logs.end(), [](const string& str) {
//             return isalpha(str[str.find(' ') + 1]);
//         });

//         // Sort letter-logs: We're only iterating on letter-logs in this case.
//         // We're creating a substring for every element we compare that doesn't include the identifier
//         // If the logs are the same except the identifier, we compare the strings, otherwise, the substrings
        
//         sort(logs.begin(), it, [](const string& str1, const string& str2) {
//             auto substr1 = string(str1.begin() + str1.find(' '), str1.end());
//             auto substr2 = string(str2.begin() + str2.find(' '), str2.end());
//             return (substr1 == substr2) ? str1 < str2 : substr1 < substr2;
//         });
        
//         return logs;
//     }
// };