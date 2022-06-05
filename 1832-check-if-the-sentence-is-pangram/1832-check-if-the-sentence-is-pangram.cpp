class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> charSet;
        for(auto& c:sentence){
            charSet.insert(c);
        }
        return charSet.size()==26;
    }
};