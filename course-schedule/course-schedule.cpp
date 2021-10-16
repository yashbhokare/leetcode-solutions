class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mapper;
        unordered_set<int> visited;
        unordered_set<int> check;
        for(int i=0;i<prerequisites.size();i++){
            auto it = mapper.find(prerequisites[i][0]);
            // Key found
            if(it!=mapper.end()){
                it->second.push_back(prerequisites[i][1]);
            }else {
                mapper.insert({prerequisites[i][0],{prerequisites[i][1]}});
            }
        }
        
        for(int course=0;course<numCourses;course++){
            if(isCycle(course,mapper,visited,check)){
                return false;
            }else {
                check.insert(course);
            }
        }
        return true;
    }
    
    bool isCycle(int& course,unordered_map<int,vector<int>>& mapper,unordered_set<int>& visited,unordered_set<int>& check){
        
        if(check.find(course) != check.end() ){
            return false;
        }
        if(visited.find(course) != visited.end()){
            return true;
        }
        
        if(mapper.find(course) == mapper.end()){
            return false;
        }
        
        
        bool ret =false;
        visited.insert(course);
        auto it = mapper.find(course);
        vector<int> parentNodes = it->second;
        for(int i=0;i<parentNodes.size();i++){
            ret = isCycle(parentNodes[i],mapper,visited,check);
            if(ret){
                break;
            }
        }
        
        visited.erase(course);
        
        return ret;

    }
};