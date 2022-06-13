class Solution {
public:
    // string removeDuplicates(string s, int k) {
    //     int length = -1;
    //     while (length != s.size()) {
    //         length = s.size();
    //         for (int i = 0, count = 1; i < s.size(); ++i) {
    //             if (i == 0 || s[i] != s[i - 1]) {
    //                 count = 1;
    //             } else if (++count == k) {
    //                 s.erase(i - k + 1, k);
    //                 break;
    //             }
    //         }
    //     }
    //     return s;
    // }
    
    string removeDuplicates(string s, int k) {
        vector<int> count(s.size());
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                count[i] = 1;
            } else {
                count[i] = count[i - 1] + 1;
                if (count[i] == k) {
                    s.erase(i - k + 1, k);
                    i = i - k;
                }
            };
        }
        return s;
}
};