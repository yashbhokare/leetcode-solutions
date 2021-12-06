class UnionFind{
    int n;
    int count;
    vector<int> root;
    vector<int> rank;
    public:
    UnionFind(int size){
        n = size;
        count = n;
        for(int i=0;i<size;i++){
            root.push_back(i);
            rank.push_back(1);
        }
    }
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }
    
    bool connected(int x,int y){
        return find(x) == find(y);
    }
    
    bool getCount(){
        return count;
    }
};


class Solution {
public:
    static bool comparator(vector<int>& a,vector<int>& b){
        return a[2]  < b[2];
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        // return prims(points,edges);
        return kruskal(points);
        
        
    }
    
    void createEdges(vector<vector<int>>& points,vector<vector<int>>& edges){
         for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x = abs(points[i][0]-points[j][0]);
                int y = abs(points[i][1]-points[j][1]);
                int dist = x + y;
                edges.push_back({i,j,dist});
            }
        }
    }
    
    int prims(vector<vector<int>>& points,vector<vector<int>>& edges){
        // unordered_map<int,set>
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x = abs(points[i][0]-points[j][0]);
                int y = abs(points[i][1]-points[j][1]);
                int dist = x + y;
                edges.push_back({i,j,dist});
            }
        }
        
        UnionFind uf(points.size());
        int result = 0;
        for(int i=0;i<edges.size();i++){
            if(!uf.connected(edges[i][0],edges[i][1])){
                uf.unionSet(edges[i][0],edges[i][1]);
                result+=edges[i][2];
            } 
            if(uf.getCount()==0){
                return result;
            }
        }
        return result;
    }
    
    
    int kruskal(vector<vector<int>>& points){
        vector<vector<int>> edges;
        createEdges(points,edges);
        UnionFind uf(points.size());
        sort(edges.begin(),edges.end(),comparator);
        int result = 0;
        for(int i=0;i<edges.size();i++){
            if(!uf.connected(edges[i][0],edges[i][1])){
                uf.unionSet(edges[i][0],edges[i][1]);
                result+=edges[i][2];
            } 
            if(uf.getCount()==0){
                return result;
            }
        }
        return result;
    }
};

// class Edge {
// public:
//     int point1;
//     int point2;
//     int cost;
//     Edge(int point1, int point2, int cost)
//         : point1(point1), point2(point2), cost(cost) {}
// };

// // Overload the < operator.
// bool operator<(const Edge& edge1, const Edge& edge2) {
//     return edge1.cost > edge2.cost;
// }

// class UnionFind {
// public:
//     UnionFind(int sz) : root(sz), rank(sz) {
//         for (int i = 0; i < sz; i++) {
//             root[i] = i;
//             rank[i] = 1;
//         }
//     }

//     int find(int x) {
//         if (x == root[x]) {
//             return x;
//         }
//         return root[x] = find(root[x]);
//     }

//     void unionSet(int x, int y) {
//         int rootX = find(x);
//         int rootY = find(y);
//         if (rootX != rootY) {
//             if (rank[rootX] > rank[rootY]) {
//                 root[rootY] = rootX;
//             } else if (rank[rootX] < rank[rootY]) {
//                 root[rootX] = rootY;
//             } else {
//                 root[rootY] = rootX;
//                 rank[rootX] += 1;
//             }
//         }
//     }

//     bool connected(int x, int y) {
//         return find(x) == find(y);
//     }

// private:
//     vector<int> root;
//     vector<int> rank;
// };

// class Solution {
// public:
//     // Kruskal's algorithm
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         if (points.size() == 0) {
//             return 0;
//         }
//         int sz = points.size();
//         priority_queue<Edge> pq;
//         UnionFind uf(sz);

//         for (int i = 0; i < sz; i++) {
//             vector<int>& coordinate1 = points[i];
//             for (int j = i + 1; j < sz; j++) {
//                 vector<int>& coordinate2 = points[j];
//                 // Calculate the distance between two coordinates.
//                 int cost = abs(coordinate1[0] - coordinate2[0]) +
//                            abs(coordinate1[1] - coordinate2[1]);
//                 Edge edge(i, j, cost);
//                 pq.push(edge);
//             }
//         }

//         int result = 0;
//         int count = sz - 1;
//         while (!pq.empty() && count > 0) {
//             Edge edge = pq.top();
//             pq.pop();
//             if (!uf.connected(edge.point1, edge.point2)) {
//                 uf.unionSet(edge.point1, edge.point2);
//                 result += edge.cost;
//                 count--;
//             }
//         }
//         return result;
//     }
// };