class Solution {
public:
    unordered_map<int,vector<int>> adjList;
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create Adj list
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        
        // Check for multiple paths from destination
        if(adjList[destination].size() > 0) return false;
        
        unordered_set<int> visited;
        return recursion(source,destination,visited);
    }
    
    bool recursion(int& source,int& destination,unordered_set<int>& visited){
            // Check result
            if(source == destination){
                return true;
            }
            // Check if cycle is detected
            if(visited.find(source) != visited.end()){
                return false;
            }
            
            // Check if it's the leaf node
            if(adjList[source].size() == 0){
                return false;
            }
        
            visited.insert(source);
            for(auto child:adjList[source]){
                if(!recursion(child,destination,visited)) return false; // Break from loop when we false
            }
            visited.erase(source);
        
            return true;
    }
    
    
};