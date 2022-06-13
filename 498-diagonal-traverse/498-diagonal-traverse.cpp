class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int index=0;
        bool changeDir = false;
        vector<int> res;
        int iMax = mat.size();
        int jMax = mat[0].size();
        int maxVal = iMax+jMax-1;
        while(index<maxVal){
            for(int i=0,j=index;i<=index && j>=0;i++,j--){
                if(changeDir && i<iMax && j<jMax){
                    res.push_back(mat[i][j]);
                }else if(!changeDir && j<iMax && i<jMax){
                    res.push_back(mat[j][i]);
                }
            }
            cout<<index<<endl;
            changeDir = !changeDir;
            index++;
        }
        return res;
    }
};