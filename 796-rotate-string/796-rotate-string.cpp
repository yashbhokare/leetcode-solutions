class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string addition = goal + goal;
        return addition.find(s)!=string::npos;

    }
};