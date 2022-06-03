class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int r=0;r<numRows;r++){
            vector<int> row;
            for(int c=0;c<=r;c++){
                if(c==0 || c==r){
                    row.push_back(1);
                }else{
                    row.push_back(result[r-1][c-1]+result[r-1][c]);
                }
            }
            result.push_back(row);
        }
        return result;
    }
    

};