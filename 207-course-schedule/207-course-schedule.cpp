class Solution {
public:
    stack<int> ans;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mapper;
        for(int i=0;i<prerequisites.size();i++){
            mapper[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> visited;
        unordered_set<int> memo;
        for(int i=0;i<numCourses;i++){
            if(isCycle(i,mapper,visited,memo)){
                return false;
            }
        }

        while(!ans.empty()){
            cout<<ans.top()<<" ";
            ans.pop();
        }
        return true;
        
    }
    
    bool isCycle(int numCourse,unordered_map<int,vector<int>>& mapper,unordered_set<int>& visited,unordered_set<int>& memo){
        if(visited.find(numCourse)!=visited.end()){
            return true;
        }
        if(memo.find(numCourse)!=memo.end()){
            return false;
        }
        
        // if(mapper.find(numCourse)==mapper.end()){
        //     // ans.push(numCourse);
        //     return false;
        // }
        
        visited.insert(numCourse);
        vector<int> childs = mapper[numCourse];
        bool res= false;
        for(int child:childs){
            if(isCycle(child,mapper,visited,memo)){
                res= true;
                break;
            }
        }
        
        visited.erase(numCourse);
        memo.insert(numCourse);
        if(res==false){
            ans.push(numCourse);
        }
        return res;
        
    }
};