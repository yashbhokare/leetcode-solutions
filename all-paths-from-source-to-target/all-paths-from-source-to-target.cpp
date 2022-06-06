class Solution {
public:
     vector<vector<int>> result;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_set<int> visited;
        vector<int> ans;
        // dfs(0,graph,visited,ans);
        bfs(graph,visited);
        return result;
    }
    
    void bfs(vector<vector<int>>& graph,unordered_set<int>& visited){
        int destination = graph.size()-1;
        queue<vector<int>> que;
        que.push({0});
        visited.insert(0);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                vector<int> queVal = que.front();
                int val = queVal.back();
                if(val == destination){
                    result.push_back(que.front());
                }
                for(auto child:graph[val]){
                    vector<int> temp = queVal;
                    temp.push_back(child);
                    que.push(temp);
                }
                que.pop();
            }
        }
    }
    
    void dfs(int index,vector<vector<int>>& graph,unordered_set<int>& visited,vector<int>& ans){
        if(index==graph.size()-1){
            ans.push_back(index);
            result.push_back(ans);
            return;
        }
        ans.push_back(index);
        visited.insert(index);
        vector<int> childs = graph[index];
        for(auto child:childs){
            if(visited.find(child)==visited.end()){
                dfs(child,graph,visited,ans);
                ans.pop_back();
            }
        }
        visited.erase(index);
    }
};