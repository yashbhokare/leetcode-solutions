class Uf{
    public:
    vector<int> root;
    int count=0;
    void init(int n){
        for(int i=0;i<n;i++){
            root.push_back(i);
        }
        count=n;
    }
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    
    void uni(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            root[rootX] = rootY;
            count--;
        }
    }
    
    int getCount(){
        return count;
    } 
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        Uf unionFind;
        int n = stones.size();
        
        unionFind.init(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    unionFind.uni(i,j);
                }
            }
        }
        return n - unionFind.getCount();
    }
};