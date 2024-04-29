class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int cnt = 0;
        unordered_map<int, int> m;
        for (int a : A)
            for (int b : B)
                ++m[a + b];
        for (int c : C)
            for (int d : D) {
                auto it = m.find(-(c + d));
                if (it != end(m))
                    cnt += it->second;
            }
        return cnt;
    }
};