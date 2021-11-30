class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<vector<int>>> edgeList;
        for(auto &time:times){
            edgeList[time[0]].push_back({time[1],time[2]});
        }
        
        vector<int> visited(n+1,0);
        vector<vector<int>> table(n+1,vector<int>(2,INT_MAX));
        // Distance for that given element from itself is 0
        table[k][0] = 0;
        if(edgeList.find(k)==edgeList.end()){
            return -1;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> s;
        s.push({0,k});
        while(!s.empty()){
            // auto pair = s.top();
            int ele = s.top().second;
            cout<<ele<<" ";
            s.pop();
            if(!visited[ele] && edgeList.find(ele)!=edgeList.end()){
                int existingDist = table[ele][0];
                for(auto edge:edgeList[ele]){
                    int vertex = edge[0];
                    int dist = min(table[vertex][0],existingDist + edge[1]);
                    s.push({dist,vertex});
                    if(table[vertex][0] > dist){
                        table[vertex][0] = dist;
                        table[vertex][1] = ele;
                    }
                }

                visited[ele]=1;
            }
        }
        int maxResult = 0;
        for(int i=1;i<=n;i++){
            cout<<table[i][0]<<"->"<<table[i][1]<<endl;
            maxResult = max(maxResult,table[i][0]);
        }
        
        return maxResult == INT_MAX ? -1 : maxResult;
    }
};