class Solution {
public:
    static bool isNotAlnum(char c) {
    return c!=' ' && isalnum(c) == 0;
}
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(),banned.end());
        unordered_map<string,int> val;
        for(char& c:paragraph){
           c = isalpha(c) ? tolower(c) : ' ';
        }
        stringstream ss(paragraph);
        string word;
        int maxCount = INT_MIN;
        string result = "";
        while(ss >> word){
            auto it = val.find(word);
            auto it2= ban.find(word);
            if(it2 != ban.end()) continue;
            if(it != val.end()){
                it->second = it->second + 1;
                if(it->second > maxCount ){
                    maxCount = it->second;
                    result = word;
            }

            }else {
                val.insert({word,0});
                if(0 > maxCount ){
                    maxCount = 0;
                    result = word;
                }
            }
            
            // cout<<result<<endl;
        }
        return result;
    }
};