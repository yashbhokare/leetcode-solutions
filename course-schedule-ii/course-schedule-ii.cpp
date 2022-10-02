class Solution {
public:  
    vector<int> result;
    vector<vector<int>> edges;
    vector<int> inDegree;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        inDegree.resize(numCourses,0);
        for(auto pre:prerequisites){
            edges[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) dfs(i);
        }
        if(result.size()==numCourses) return result;
        return {};
        
        
    }
    
    void dfs(int course){
        result.push_back(course);
        inDegree[course]=-1;
        for(auto child:edges[course]){
            if(--inDegree[child]==0){
                dfs(child);
            }
        }
    }
};

// class Solution {
// public:
//     unordered_map<int,vector<int>> mapper;
//     unordered_map<int,int> memo;
//     unordered_set<int> visited;
//     unordered_set<int> added;
//     vector<int> ans;
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         for(auto pre:prerequisites){
//             mapper[pre[0]].push_back(pre[1]);
//         }
        
       
//         for(int i=0;i<numCourses;i++){
//             if(isCycle(i,visited)) return {};
//         }
//         return ans;
//     }
    
//     bool isCycle(int course,unordered_set<int>& visited){
// //         Check if course exists in mapper
// //         if(mapper.find(course)==mapper.end()) return false;

//         // Course already exists so a cycle is detected
//         if(visited.find(course)!=visited.end()) return true;
        
//           // Check if it exists in memo
//         if(memo.find(course)!=memo.end()) return memo[course];

        
//         // Mark course as visited
//         visited.insert(course);
        
//         bool result = false;
//         // Check for all it's children
//         for(auto childCourse:mapper[course]){
//             result = isCycle(childCourse,visited);
            
//             if(result) break;
//         }

//         ans.push_back(course);
//         visited.erase(course);
//         memo[course] = result;
//         return result;
//     }
// };