class UnionFind{
    public:
        vector<int> root;
        int n;
        int count;
        UnionFind(int size){
            n = size;
            count = size;
            for(int i=0;i<size;i++){
                root.push_back(i);
            }
        }
    
        int find(int x){
            while(x != root[x]){
                x=root[x];
            }
            return x;
        }
    
        bool unionSet(int x,int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX==rootY){
               return false;
            } else {
                root[rootY] = rootX;
                count--;
            }
            return true;
        }
    
        int getCount(){
            return count;
        }
     

    void display(){
        for(int i=0;i<n;i++){
                cout<<root[i]<<" ";
        }
        cout<<endl;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            if(!uf.unionSet(x,y)) return false;
        }
        if(uf.getCount() == 1) return true;
        // uf.display();
        return false;
    }
    
    
};