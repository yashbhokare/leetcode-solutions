class Solution {
public:
   
    vector<int> workDone;
    unordered_map<int,int> mapper;
    vector<int> amountPainted(vector<vector<int>>& paint) {
        for(auto p:paint){
            workDone.push_back(calAmountPainted(p[0],p[1]));
        }
        return workDone;
    }
    
    int calAmountPainted(int start, int end){
        int work=0;
        while(start<end){
            // start not found
            if(mapper.find(start)==mapper.end()){
                mapper[start]=end;
                work++;
                start++;
            }else {
                int newStart = mapper[start];
                mapper[start] = max(mapper[start],end);
                start = newStart;
            }
        }
        return work;
    }


};


// class Solution {
// public:
//     vector<int>par;
//     int n;
    
//     void make_set(int v){
//         par[v] = v;
//     }
    
//     int find_set(int v){
//         if(par[v]==v)
//             return v;
//         return par[v] = find_set(par[v]);
//     }
    
//     void union_set(int u, int v){
//         u = find_set(u);
//         v = find_set(v);
        
//         par[u] =v;
//     }
    
//     vector<int> amountPainted(vector<vector<int>>& paint) {
//         int maxlen = 0;
//         int minlen = INT_MAX;
//         for(auto& v:paint){
//             minlen = min(minlen, v[0]);
//             maxlen = max(maxlen, v[1]);
//         }
//         par.resize(maxlen+2);
        
//         for(int i=minlen; i<=maxlen+1; i++){
//             make_set(i);
//         }
//         n = paint.size();
//         vector<int>ans(n,0);
        
//         for(int i=0; i< paint.size(); i++){
//             int l = paint[i][0]; int r = paint[i][1];
            
//             for(l=find_set(l); l<r; l=find_set(l)){
//                 ans[i]++;
//                 union_set(l, l+1);
//             }
//         }
        
//         return ans;
//     }
// };