

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
            // cout<<startX<<","<<startY<<"->"<<treeX<<","<<treeY<<" - "<<distance<<endl;
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