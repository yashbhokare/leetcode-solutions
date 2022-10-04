class Solution {
public:
unordered_map<string, string> mp;

string findFunc(string& s){
    if(mp.find(s) == mp.end()) mp[s] = s;
    while(mp[s] != s){
        s = mp[s];
    }
    return mp[s];
}

bool unionFunc(string& s1, string& s2){
    string sr1 = findFunc(s1), sr2 = findFunc(s2);
    if(sr1 == sr2) return false;
    mp[sr1] = sr2;
    return true;
}

bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
    int n1 = sentence1.size(), n2 = sentence2.size();
    if(n1 != n2) return false;
    
    for(auto pair : similarPairs){
        unionFunc(pair[0], pair[1]);
    }
    
    for(auto i = 0; i < n1; i++){
        if(findFunc(sentence1[i]) != findFunc(sentence2[i])) return false;
    }
    
    return true;
}
};