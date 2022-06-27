class Solution {
public:
    int minPartitions(string n) {
        int val= *max_element(n.begin(), n.end()) - '0';
        cout<<val;
        return val;
    }
};