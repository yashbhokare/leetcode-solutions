class Solution {
public:
    unordered_map<int,vector<int>> mapper;
    unordered_set<int> memo;
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>> courses;
//         unordered_map<int,int> inDegrees;
//         for(int i=0;i<numCourses;i++){
//             inDegrees[i]=0;
//         }
//         for(auto preReq:prerequisites){
//             courses[preReq[1]].push_back(preReq[0]);
//             inDegrees[preReq[0]]++;
//         }
        
//         queue<int> q;
//         for(auto it=inDegrees.begin();it!=inDegrees.end();it++){
//             if(it->second==0){
//                 q.push(it->first);
//             }
//         }
        
//         unordered_set<int> visited;
        
//         vector<int> result;
//         if(q.size()==0) return {};
//         while(!q.empty()){
//             int val = q.front();
//             q.pop();
//             visited.insert(val);
//             result.push_back(val);
//             for(auto course:courses[val]){
//                 if(visited.find(course) == visited.end()){
//                     inDegrees[course]--;
//                     if(inDegrees[course]==0){
//                         q.push(course);
//                     } 
//                 }
//             }
            
//         }
//         if(result.size() == numCourses){
//             return result;
//         }
//         return {};
        for(auto& preq:prerequisites){
            mapper[preq[0]].push_back(preq[1]);
        }
        unordered_set<int> visited;
        for(int i=0;i<numCourses;i++){
            if(!rec(i,visited)) return {};
        }
        return ans;
    }
        bool rec(int course,unordered_set<int>& visited){
        // Already visited so cycle detected
        if(visited.find(course)!=visited.end()) return false;
        
        // No cycle as already visited
        if(memo.find(course)!=memo.end()) return true;
        
        // Course doesn't have any prereq
        // if(mapper.find(course)==mapper.end()) return true;
        
        visited.insert(course);
        bool result=true;
        vector<int> neighbours=mapper[course];
        for(auto& neighbour:neighbours){
            result= rec(neighbour,visited);
            if(!result) break;
        }
        
        //Backtrack and unvist the node
        visited.erase(course);
        // cout<<course<<endl;
        ans.push_back(course);
        memo.insert(course);
        return result;
    }
};