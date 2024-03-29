class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> set;
        for(auto word:words){
            set.insert(word);
        }
        
        for(auto word:words){
            for(int i=1;i<word.length();i++){
                set.erase(word.substr(i));
            }
        }
        
        int res = 0;
        for(auto it=set.begin();it!=set.end();it++){
            string s = *it;
            res = res + s.length() + 1;
        }
        return res;
    }
};