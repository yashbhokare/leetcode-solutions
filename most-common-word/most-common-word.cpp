class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(),banned.end());
        unordered_map<string,int> mapper;
        // string new_para = "";
        for(auto& ch:paragraph){
            if((ch>='a' && ch<='z')){
                continue;
                // new_para.push_back(ch);
            }else if(ch>='A' && ch<='Z'){
                ch = ch -'A'+'a';
                // new_para.push_back(ch);
            }else{
                ch = ' ';
                // new_para.push_back(' ');
            }
        }
        
        stringstream ss(paragraph);
        string word;
        int maxVal = 0;
        string result = "";
        while(ss>>word){
            if(ban.find(word)==ban.end()){
                mapper[word]++;
                if(mapper[word]>maxVal){
                    maxVal =mapper[word];
                    result=word;
                }
            }
        }
        return result;

        
    }
};