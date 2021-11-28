class Solution {
public:
    unordered_map<int,vector<int>> adjList;
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {

        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        
        if(adjList[destination].size() > 0) return false;
        unordered_set<int> visited;
        return recursion(source,destination,visited);
    }
    
    bool recursion(int& source,int& destination,unordered_set<int>& visited){
            
            if(source == destination){
                return true;
            }
            
            if(visited.find(source) != visited.end()){
                return false;
            }
            
            if(adjList[source].size() == 0){
                return false;
            }
        
            visited.insert(source);
            for(auto child:adjList[source]){
                if(!recursion(child,destination,visited)) return false;
            }
            visited.erase(source);
        
            return true;
    }
    
    
};