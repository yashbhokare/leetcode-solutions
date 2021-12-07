// class Solution {
// public:

//     int removeStones(vector<vector<int>>& stones) {
//         for (int i = 0; i < stones.size(); ++i){
//             cout<<stones[i][0]<<~stones[i][1]<<endl;
//             uni(stones[i][0], ~stones[i][1]);
//         }
//         return stones.size() - islands;
//     }

//     unordered_map<int, int> f;
//     int islands = 0;

//     int find(int x) {
//         if (!f.count(x)) f[x] = x, islands++;
//         if (x != f[x]) f[x] = find(f[x]);
//         return f[x];
//     }

//     void uni(int x, int y) {
//         x = find(x), y = find(y);
//         if (x != y) f[x] = y, islands--;
//     }
// };

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        f = vector<int>(n);
        count = n;
        for(int i=0;i<n;i++) f[i] = i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uni(i,j);
            }
        }
        return n - count;
    }
    
    vector<int> f;
    int count;
    
    int find(int x) {
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            f[x] = y;
            count--;
        }
    }
};