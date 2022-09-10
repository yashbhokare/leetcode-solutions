class Solution {
public:
    unordered_map<int,vector<int>> mapper;
    unordered_map<int,int> memo;
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto pre:prerequisites){
            mapper[pre[0]].push_back(pre[1]);
        }
        
       
        for(int i=0;i<numCourses;i++){
            
            if(isCycle(i,visited)) return false;
        }
        return true;
    }
    
    bool isCycle(int course,unordered_set<int>& visited){
        // Check if course exists in mapper
        if(mapper.find(course)==mapper.end()) return false;
    
        
        // Course already exists so a cycle is detected
        if(visited.find(course)!=visited.end()) return true;
        
          // Check if it exists in memo
        if(memo.find(course)!=memo.end()) return memo[course];

        
        // Mark course as visited
        visited.insert(course);
        
        bool result = false;
        // Check for all it's children
        for(auto childCourse:mapper[course]){
            result = isCycle(childCourse,visited);
            if(result) break;
        }
        
        visited.erase(course);
        memo[course] = result;
        return result;
    }
};