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
    
    bool union_value(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            root[rootX] =rootY;
            count--;
            return true;
        }else {
            return false;
        }
    }
    
    int getCount(){
        return count;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto edge:edges){
            if(!uf.union_value(edge[0],edge[1])) return false;
        }
        return uf.getCount()==1;
    }
};