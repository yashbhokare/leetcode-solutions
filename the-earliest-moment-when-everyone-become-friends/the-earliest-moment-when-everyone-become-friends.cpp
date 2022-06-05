class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        initalize(n);
        for(auto& log:logs){
            unionF(log[1],log[2]);
            if(getCount()==1) return log[0];
        }
        return -1;
    }
    
    vector<int> root;
    int count;
    
    void initalize(int size){
        for(int i=0;i<size;i++){
            root.push_back(i);
        }
        count=size;
    }
    
    int find(int x){
        if(x==root[x]) return x;
        return root[x]=find(root[x]);
    }
    
    void unionF(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            root[rootY]=rootX;
            count--;
        }
    }
    
    int getCount(){
        return count;
    }
    
};