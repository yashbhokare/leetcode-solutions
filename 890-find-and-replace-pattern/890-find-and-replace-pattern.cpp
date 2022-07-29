class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string newPattern = "";
        unordered_map<char,int> mapper;
        int i=0;
        for(auto ch:pattern){
            if(mapper.find(ch)!=mapper.end()){
                newPattern+=to_string(mapper[ch]);
            }else {
                mapper[ch] = i;
                newPattern+=to_string(i);
                i++;
            }
        }

        vector<string> ans;
        for(auto word:words){
            if(word.size()==pattern.size() && isPatternEqual(word,newPattern)){
                ans.push_back(word);
            }
        }
        return ans;
    }
    
    bool isPatternEqual(string input,string result){
        // cout<<input<<" "<<result<<endl;
        // if(input.size()!=result.size()) return false;
        string newPattern = "";
        int i=0;
        unordered_map<char,int> mapper;
        for(int j=0;j<input.size();j++){
            if(mapper.find(input[j])!=mapper.end()){
                newPattern+=to_string(mapper[input[j]]);
            }else {
                mapper[input[j]] = i;
                newPattern+=to_string(i);
                i++;
            }
            if(newPattern[j]!=result[j]) return false;
        }
        // cout<<newPattern<<" "<<result<<endl;
        return true;
    }
};