class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int,vector<int>> mapper;
    unordered_map<int,bool> cache;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        for(auto pre:prerequisites) mapper[pre[0]].push_back(pre[1]);
        
        for(int course=0;course<numCourses;course++){
            if(isCycle(course)) return false;
        }
        return true;
    }
    
    bool isCycle(int course){
        //If already cached return that
        if(cache.find(course)!=cache.end()) return cache[course];
        
        // Course does not exist on mapper so valid
        if(mapper.find(course)==mapper.end()) return false;
        
        //If course already visited return cycle found
        if(visited.find(course)!=visited.end()) return true;
        
        // Mark as visited
        visited.insert(course);
        bool res = false;
        for(auto child:mapper[course]){
            res=isCycle(child);
            if(res) break;
        }
        
        visited.erase(course);
        cache[course] = res;
        return res;
        
    }
};