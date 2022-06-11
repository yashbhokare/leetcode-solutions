class Solution {
public:
    // vector<int> getRowBruteForce(int rowIndex) {
    //     vector<vector<int>> result;
    //     vector<int> row;
    //     for(int r=0;r<=rowIndex;r++){
    //         row={};
    //         for(int c=0;c<=r;c++){
    //             if(c==0 || c==r){
    //                 row.push_back(1);
    //             }else{
    //                 row.push_back(result[r-1][c-1]+result[r-1][c]);
    //             }
    //         }
    //         result.push_back(row);
    //     }
    //     return row;
    // }
    
    vector<int> getRow(int rowIndex){
        vector<int> ans = vector<int>(rowIndex + 1, 1);
        for (int i = 1; i < rowIndex; i++)
          for (int j = i; j > 0; j--)
            ans[j] = ans[j] + ans[j - 1];  // ans[j] = ans[j-1] + ans[j]
        return ans;
      }
    
};