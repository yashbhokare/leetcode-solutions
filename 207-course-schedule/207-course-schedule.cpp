class Solution {
public:
    unordered_map<int,vector<int>> mapper;
    unordered_set<int> visited;
    unordered_map<int,int> cache;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return canFinishUsingTopologicalSort(numCourses,prerequisites);
        // return canFinishUsingRecursion(numCourses,prerequisites);
    }

    bool canFinishUsingTopologicalSort(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> inDegree(numCourses,0);
        for(auto pre:prerequisites){
            mapper[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> result;
        while(!q.empty()){
            int course = q.front();
            result.push_back(course);
            q.pop();
            visited.insert(course);
            // if(visited.find(course)==visited.end()){
                for(auto child:mapper[course]){
                    inDegree[child]--;
                    if(inDegree[child]==0){
                        q.push(child);
                    }
                }
            // }
            
        }
        if(result.size()==numCourses) return true;
        return false;
    }
    
     bool canFinishUsingRecursion(int numCourses, vector<vector<int>>& prerequisites) {
            for(auto pre:prerequisites){
                mapper[pre[0]].push_back(pre[1]);
            }
         
            for(int i=0;i<numCourses;i++){
                if(isCycle(i)) return false;
            }
         return true;
     }
    
    bool isCycle(int course){
        if(visited.find(course)!=visited.end()) return true;
        
        if(mapper.find(course)==mapper.end()) return false;
        
        if(cache.find(course)!=cache.end()) return cache[course];
        
        bool res = false;
        visited.insert(course);
        for(auto child:mapper[course]){
            res = isCycle(child);
            if(res) break;
        }
        visited.erase(course);
        
        // cout<<course<<" ";
        cache[course] = res;
        return cache[course];
        
    }
};