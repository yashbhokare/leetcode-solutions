class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        stack<int> s;
        s.push(0);
        visited[0] = true;
        while(!s.empty()){
            int index = s.top();
            s.pop();
            vector<int> keys = rooms[index];
            for(int key:keys){
                if(!visited[key]){
                    visited[key] = true;
                    s.push(key);
                }
            }
        }

        for(int i=0;i<visited.size();i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};