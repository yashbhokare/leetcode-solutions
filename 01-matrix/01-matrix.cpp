// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int maxRow = mat.size();
//         int maxCol = mat[0].size();
//         vector<vector<int>> result(mat.size(),vector<int>(mat[0].size(),0));
//         for(int r=0;r<maxRow;r++){
//             for(int c=0;c<maxCol;c++){
//                 if(mat[r][c] !=0){
//                     result[r][c] = bfs(r,c,mat);
//                 }
//             }
//         }
//         return result;
//     }
    
//     int bfs(int r,int c,vector<vector<int>>& mat){
//         int maxRow = mat.size();
//         int maxCol = mat[0].size();
//         queue<pair<int,int>> q;
//         vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
//         q.push({r,c});
//         int step = 0;
//         while(!q.empty()){
//             int size = q.size();
//             for(int i=0;i<size;i++){
//                 int curR = q.front().first;
//                 int curC = q.front().second;
//                 // cout<<curR<<curC<<endl;
//                 visited[curR][curC] = 1;
//                 if(mat[curR][curC] == 0){
//                     // cout<<"Step"<<step<<endl;
//                     return step;
//                 }
//                 if( curR - 1 >=0 && visited[curR - 1][curC] == 0){
//                     if(mat[curR - 1][curC] == 0){
//                         return step+1;
//                     }
//                     q.push({curR - 1,curC});
//                 }
                    
//                 if( curR + 1 <maxRow && visited[curR + 1][curC] == 0){
//                     if(mat[curR + 1][curC] == 0){
//                         return step+1;
//                     }
//                      q.push({curR + 1,curC});
//                 }
                
//                 if( curC - 1 >=0 && visited[curR][curC-1] == 0){
//                     if(mat[curR][curC-1] == 0){
//                         return step+1;
//                     }
//                      q.push({curR,curC-1});
//                 }
                   
//                 if( curC + 1 <maxCol && visited[curR][curC+1] == 0){
//                     if(mat[curR][curC+1] == 0){
//                         return step+1;
//                     }
//                     q.push({curR,curC+1});
//                 }
                    
//                 q.pop();
//             }
//             step++;
//         }
//         return step;
//     }
// };
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};