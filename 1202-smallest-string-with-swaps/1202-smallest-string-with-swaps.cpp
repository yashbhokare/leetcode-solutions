class UnionFind {
    public:
    int n;
    vector<int> root;
    UnionFind(int size){
        n = size;
        for(int i=0;i<size;i++){
            root.push_back(i);
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
            root[rootY] = rootX;
        }
    }
    
    // void display(){
    //     for(int i=0;i<n;i++){
    //         cout<<root[i]<<" ";
    //     }
    //     cout<<endl;
    // }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        for(int i=0;i<pairs.size();i++){
            uf.unionSet(pairs[i][0],pairs[i][1]);
        }
        // uf.display();
        vector<vector<int>> maps(s.size());
        for(int i=0;i<s.size();i++){
            maps[uf.find(i)].push_back(i);
        }

        for(auto &indexes:maps){
            string newString = "";
            for(auto &index: indexes){
                newString+=s[index];
            }
            sort(newString.begin(),newString.end());
            for(int i=0;i<newString.size();i++){
                s[indexes[i]] = newString[i];
            }
        }
        return s;
        
    }
};


// class Solution {
// public:
//     vector<bool> visited;
//     vector<int> newStringIndexes;
//     string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
//         unordered_map<int,vector<int>> adjList;
//         for(int i=0;i<pairs.size();i++){
//             int x = pairs[i][0];
//             int y = pairs[i][1];
//             adjList[x].push_back(y);
//             adjList[y].push_back(x);
//         }
//          visited.resize(s.size(),false);
        

//         for(int i=0;i<s.size();i++){
//             if(!visited[i]){
//                 string newString = "";
//                 newStringIndexes.clear();
//                 dfs(i,s,newString,newStringIndexes,adjList);
                
//                 sort(newString.begin(),newString.end());
//                 sort(newStringIndexes.begin(),newStringIndexes.end());
                
//                 for(int i=0;i<newStringIndexes.size();i++){
//                     s[newStringIndexes[i]] = newString[i];
//                 }
//             }
//         }
//         return s;
//     }
    
//     void dfs(int index,string& ipString,string& newString,vector<int>& newStringIndexes, unordered_map<int,vector<int>>& adjList ){
//         newString+=ipString[index];
//         newStringIndexes.push_back(index);
//         visited[index]=true;
//         for(auto listVal:adjList[index]){
//             if(!visited[listVal]){
//                 dfs(listVal,ipString,newString,newStringIndexes,adjList);
//             }
//         }
        
//     }
// };