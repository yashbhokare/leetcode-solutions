class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> rows;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    rows.push_back(1);
                }else {
                    // cout<<result[i-1][j+1];
                    rows.push_back(result[i-1][j]+result[i-1][j-1]);
                }
            }
            result.push_back(rows);
            cout<<rows.size()<<endl;
        }
        return result;
    }
};