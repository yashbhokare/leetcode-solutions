class Solution {
public:
    vector<int> root;
    int count;
    int findCircleNum(vector<vector<int>>& isConnected) {
        initalize(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=i+1;j<isConnected.size();j++){
                if(isConnected[i][j]){
                    unionSet(i,j);
                }
            }
        }
        unordered_set<int> res;
        for(int i=0;i<isConnected.size();i++){
            res.insert(root[i]);
        }
        return count;
    }
    
    void initalize(int size){
        count =size;
        for(int i=0;i<size;i++){
            root.push_back(i);
        }
    }
    
    int find(int x){
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            for(int i=0;i<root.size();i++){
                if(root[i] == rootY){
                    root[i] = rootX;
                }
            }
            count--;
        }
    }
};