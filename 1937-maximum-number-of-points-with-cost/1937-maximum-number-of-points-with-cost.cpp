class Solution {
public:
//     long long maxPoints(vector<vector<int>>& points) {
//         long long result =0;
//         for(int r=points.size()-1;r>=0;r--){
//             for(int c1=0;c1<points[0].size();c1++){
//                 long long max_val = points[r][c1];
//                 long long curr = points[r][c1];
//                 if(r+1<points.size()){
                    
//                     for(int c2=0;c2<points[0].size();c2++){
//                         long long val = curr + points[r+1][c2] - abs(c2-c1);
//                         max_val = max(max_val,val);
//                     }
//                 }
//                 points[r][c1] = max_val;
//                 if(r==0){
//                     result = max(result,max_val);
//                 }
//             }
//         }
//         return result;
//     }
    
    long long maxPoints(vector<vector<int>>& P) {
        long long m = P.size(), n = P[0].size();
        vector<long long> pre(n);
        for (int i = 0; i < n; ++i) pre[i] = P[0][i];
        for (int i = 1; i < m ; ++i){
            vector<long long> lft(n, 0), rgt(n, 0), cur(n, 0);
            lft[0] = pre[0];
            rgt[n - 1] = pre[n - 1];
            for (int j = 1; j < n; ++j){
                lft[j] = max(lft[j - 1] - 1, pre[j]);
            }
            for (int j = n - 2; j >= 0; --j){
                rgt[j] = max(rgt[j + 1] - 1, pre[j]);
            }
            for (int j = 0; j < n; ++j){
                cur[j] = P[i][j] + max(lft[j], rgt[j]);
                cout<<cur[j]<<" ";
            }
            cout<<endl;
            pre = cur;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, pre[i]);
        return ans;
    }
};