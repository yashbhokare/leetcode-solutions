class Solution {
public:
    unordered_map<int,vector<int>> mapper;
    unordered_set<int> memo;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& preq:prerequisites){
            mapper[preq[0]].push_back(preq[1]);
        }
        unordered_set<int> visited;
        for(int i=0;i<numCourses;i++){
            if(!rec(i,visited)) return false;
        }
        return true;
    }
    
    bool rec(int course,unordered_set<int>& visited){

        // Already visited so cycle detected
        if(visited.find(course)!=visited.end()) return false;
        
        // No cycle as already visited
        if(memo.find(course)!=memo.end()) return true;
        
        // Course doesn't have any prereq
        if(mapper.find(course)==mapper.end()) return true;
        
        visited.insert(course);
        bool result=true;
        vector<int> neighbours=mapper[course];
        for(auto& neighbour:neighbours){
            result= rec(neighbour,visited);
            if(!result) break;;
        }
        
        //Backtrack and unvist the node
        visited.erase(course);
        memo.insert(course);
        return result;
    }
};