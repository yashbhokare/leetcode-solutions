class UnionFind {
    vector<int> root;
    int size;
    int count;
    public:

    UnionFind(int n){
        root.resize(n);
        size=n;
        count=n;
        for(int i=0;i<n;i++){
            root[i]=i;
        }
    }
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    
    void union_value(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            root[rootX] =rootY;
            count--;
        }
    }
    
    int getCount(){
        return count;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto edge:edges){
            uf.union_value(edge[0],edge[1]);
        }
        
        return uf.getCount();
    }
};