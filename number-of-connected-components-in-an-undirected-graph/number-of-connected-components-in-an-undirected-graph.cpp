class UnionFind{
    public:
    UnionFind(int size){
        count = size;
        for(int i=0;i<size;i++){
            root.push_back(i);
            rank.push_back(1);
        }
    }
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    
    void unionSet(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            if(rank[rootX] < rank[rootY]){
                root[rootX] = rootY;
                rank[rootY]+= rank[rootX];
            }else{
                root[rootY] = rootX;
                rank[rootX]+= rank[rootY];
            }
            count--;
        }
    }
    
    int getCount(){
        return count;
    }
    
    private:
    int n;
    int count;
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(int i=0;i<edges.size();i++){
            uf.unionSet(edges[i][0],edges[i][1]);
        }
        return uf.getCount();
    }
};