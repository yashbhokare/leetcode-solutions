class Solution {
public:
    unordered_map<int,vector<int>> mapper;
    unordered_map<int,int> memo;
    unordered_set<int> visited;
    unordered_set<int> added;
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto pre:prerequisites){
            mapper[pre[0]].push_back(pre[1]);
        }
        
       
        for(int i=0;i<numCourses;i++){
            if(isCycle(i,visited)) return {};
        }
        return ans;
    }
    
    
    bool isCycle(int num,unordered_set<int>& visited){
        // Number doesn't exist so no pre req
        // if(mapper.find(num)==mapper.end()) return false;
        
        // Already checked
        if(added.find(num)!=added.end()) return false;
        
        // Cycle exisits
        if(visited.find(num)!=visited.end()) return true;
        
        visited.insert(num);
        bool result = false;
        for(auto child:mapper[num]){
            if(isCycle(child,visited)){
                result = true;
                break;
            }
        }
        
        visited.erase(num);
        if(!result) {
            ans.push_back(num);
            added.insert(num);
        }
        return result;
    }
};