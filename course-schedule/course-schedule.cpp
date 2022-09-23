class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mapper;
        for(auto preq:prerequisites) mapper[preq[0]].push_back(preq[1]);
        
        unordered_set<int> visited;
        unordered_set<int> memo;
        for(int i=0;i<numCourses;i++){
            if(isCycle(i,visited,memo,mapper)) return false;
            memo.insert(i);
        }
        return true;
    }
    
    
    bool isCycle(int num,unordered_set<int>& visited,unordered_set<int>& memo,unordered_map<int,vector<int>>& mapper){
        // Number doesn't exist so no pre req
        if(mapper.find(num)==mapper.end()) return false;
        
        // Already checked
        if(memo.find(num)!=memo.end()) return false;
        
        // Cycle exisits
        if(visited.find(num)!=visited.end()) return true;
        
        visited.insert(num);
        bool result = false;
        for(auto child:mapper[num]){
            if(isCycle(child,visited,memo,mapper)){
                result = true;
                break;
            }
        }
        
        visited.erase(num);
        if(!result) memo.insert(num);
        return result;
    }
};