// class Solution {
// public:
//     vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
//     int cutOffTree(vector<vector<int>>& forest) {
//         int total = 0;
//         int count=0;
//         int minValue = INT_MAX;
//         int x=0,y=0;
//         for(int r=0;r<forest.size();r++){
//             for(int c=0;c<forest[0].size();c++){
//                 if(forest[r][c]!=0){
//                     total++;
//                     if(forest[r][c]<minValue){
//                         minValue = forest[r][c];
//                         x = r;
//                         y = c;
//                     }
//                 }
//             }
//         }
//         if(total==1) return -1;
//         dfs(x,y,forest,count);
//         // cout<<count<<endl;
//         cout<<total;
//         if(count==total) return total-1;
//         return -1;
        
//     }
    
    
//     void dfs(int x, int y,vector<vector<int>>& forest,int &count){
        
//         count++;
//         int n = forest.size();
//         int m = forest[0].size();
//         int baseValue = forest[x][y];
//         cout<<baseValue<<endl;
//         // forest[x][y] = 0;
//         long minValue = INT_MAX;
//         int minX=-1,minY=-1;
//         for(int i=0;i<dir.size();i++){
//             int newX = dir[i][0]+x;
//             int newY = dir[i][1]+y;
//             if(newX>=0 && newX<n && newY>=0 && newY<m && forest[newX][newY]!=0){
//                 if(forest[newX][newY]>baseValue && forest[newX][newY]<minValue){
//                     minValue = forest[newX][newY];
//                     minX = newX;
//                     minY = newY;
//                 }
//             }
//         }
//         if(minX==-1) return;
//         else dfs(minX,minY,forest,count);
        
//     }
// };

class Solution {
public:
    int BFS(vector<vector<int>> &forest, int sX, int sY, int dX, int dY){
        int n=forest.size();
        int m=forest[0].size();
        int X[4]={1,-1,0,0};
        int Y[4]={0,0,1,-1};
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({sX,sY});
        vis[sX][sY]=true;
        int res=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                if(curr.first==dX && curr.second==dY){
                    return res;
                }
                for(int dir=0;dir<4;dir++){
                    int newX=curr.first+X[dir];
                    int newY=curr.second+Y[dir];
                    if(newX<0 || newY<0 || newX==n || newY==m || forest[newX][newY]==0 || vis[newX][newY]==true){
                        continue;
                    }
                    vis[newX][newY]=true;
                    q.push({newX,newY});
                }
            }
            res++;
        }
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        vector<vector<int>> trees;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1){
                    trees.push_back({forest[i][j],i,j});
                }
            }
        }
        sort(trees.begin(),trees.end());
        int res=0;
        int startX=0;
        int startY=0;
        for(auto tree: trees){
            int treeX=tree[1];
            int treeY=tree[2];
            int distance=BFS(forest,startX,startY,treeX,treeY);
            if(distance==-1){
                return -1;
            }
            res+=distance;
            startX=treeX;
            startY=treeY;
        }
        return res;
    }
};