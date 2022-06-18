class Solution {
public:
    unordered_map<int,vector<int>> mapper;
    unordered_map<int,bool> memo;
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto pre:prerequisites){
            mapper[pre[0]].push_back(pre[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!backTrack(i)) return false;
        }
        return true;
    }
    
    
    bool backTrack(int course){
          // If course already in memo return result;
        if(memo.find(course)!=memo.end()) return memo[course];
        
        //Course not found return true
        if(mapper.find(course)==mapper.end()){
            return true;
        }
        
        //Course already visited return false as cycle detected
        if(visited.find(course)!=visited.end()) return false;

      
        

        cout<<course;
        // Mark course as visited
        visited.insert(course);
        bool res = true;
        
        for(auto child:mapper[course]){
            res = backTrack(child);
            if(res==false) break;
        }
        
        cout<<res;
        visited.erase(course);
        
        memo[course] = res;
        
        return memo[course];
    }
};