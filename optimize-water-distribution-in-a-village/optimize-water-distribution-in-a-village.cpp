class UnionFind {
    public:
    int n;
    int count;
    vector<int> root;
    vector<int> cost;
    UnionFind(int size){
        n = size;
        count =n;
        for(int i=0;i<size;i++){
            root.push_back(i);
        }
    }
    
    int find(int x){
        if(root[x]==x){
            return x;
        }
        return root[x]=find(root[x]);
    }
    
    bool unionSet(int x,int y,int costing){
        int rootX = find(x);
        int rootY  = find(y);
        if(rootX!=rootY){
            root[rootY] = rootX;
            count--;
            return true;
        } else {
            return false;
        }

    }
    
    void display(){
        for(int i=0;i<n;i++){
                cout<<root[i]<<" "<<cost[i]<<endl;
        }
        cout<<endl;
    }
    
    int getCount(){
        return count;
    }
};

class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
    
    int minCostToSupplyWater(int n, vector<int>& wells,vector<vector<int>>& pipes) {
        vector<vector<int>> orderedEdges;
        for(int i = 0; i < wells.size(); ++i) {
             orderedEdges.push_back({0,i+1,wells[i]});
        }
        for(int i=0;i<pipes.size();i++){
            orderedEdges.push_back(pipes[i]);
        }
        sort(orderedEdges.begin(),orderedEdges.end(),comparator);
        UnionFind uf(n+1);
        // int min = *min_element(wells.begin(),wells.end());
        int ans = 0;
        for(int i=0;i<orderedEdges.size();i++){
            int x = orderedEdges[i][0];
            int y = orderedEdges[i][1];
            int cost = orderedEdges[i][2];
            if(uf.unionSet(x,y,cost)){
                 ans+=cost;
            }
        }
        return ans;
        
    }
};