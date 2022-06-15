class Solution {
public:
    vector<vector<int>> dir = {
        {0,1},{1,0},{0,-1},{-1,0}
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> result(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<int,int>> q;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) q.push({i,j});
                else result[i][j]= INT_MAX;
            }
        }
        
        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newR = r+dir[i][0];
                int newC = c + dir[i][1];
                
                if(newR>=0 && newR<result.size() && newC>=0 && newC<result[0].size() && result[newR][newC]!=0){
                    if(result[r][c] + 1 < result[newR][newC]){
                        result[newR][newC] = result[r][c] + 1;
                        q.push({newR,newC});
                    }
                }
            }
        }

        return result;
    }
};