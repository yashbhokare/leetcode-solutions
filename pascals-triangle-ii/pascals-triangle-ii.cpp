class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
        vector<int> row;
        for(int r=0;r<=rowIndex;r++){
            row={};
            for(int c=0;c<=r;c++){
                if(c==0 || c==r){
                    row.push_back(1);
                }else{
                    row.push_back(result[r-1][c-1]+result[r-1][c]);
                }
            }
            result.push_back(row);
        }
        return row;
    }
};