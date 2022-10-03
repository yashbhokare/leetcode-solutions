class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int,vector<int>> mapper;
    unordered_map<int,bool> cache;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
    return canFinishUsingTopologicalSort(numCourses,prerequisites);
    }
    
    bool canFinishUsingDFS(int numCourses, vector<vector<int>>& prerequisites) {
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
        // if(mapper.find(course)==mapper.end()) return false;
        
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
        cout<<course<<endl;
        cache[course] = res;
        return res;
        
    }
    
    bool canFinishUsingTopologicalSort(int numCourses, vector<vector<int>>& prerequisites){
        unordered_map<int,vector<int>> mapper;
        vector<int> inDegree(numCourses,0);
        vector<int> result;
        queue<int> q;
          for(auto pre:prerequisites) {
             mapper[pre[1]].push_back(pre[0]);
             inDegree[pre[0]]++;
         }
        
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int course = q.front();
            q.pop();
            result.push_back(course);
            for(auto child:mapper[course]){
                inDegree[child]--;
                if(inDegree[child]==0){
                    q.push(child);
                }
            }
        }
        if(result.size()==numCourses) return true;
        return false;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};