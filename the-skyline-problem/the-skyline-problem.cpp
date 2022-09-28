class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Iterate over all buildings, for each building i,
        // add (position, i) to edges.
        vector<vector<int>> edges;
        for (int i = 0; i < buildings.size(); ++i){
            edges.push_back({buildings[i][0], i});
            edges.push_back({buildings[i][1], i});
        }
        
        // Sort edges by non-decreasing order.
        sort(edges.begin(), edges.end());
        
        // Initailize an empty Priority Queue 'live' to store all the newly added buildings,
        // an empty list 'answer' to store the skyline key points.
        priority_queue<pair<int, int>> live;
        vector<vector<int>> answer;
        int idx = 0;
        
        // Iterate over all the sorted edges.
        while (idx < edges.size()){
            
            // Since we might have multiple edges at same x,
            // Let the 'currX' be the current position.
            int currX = edges[idx][0];
            
            // While we are handling the edges at 'currX':
            while (idx < edges.size() && edges[idx][0] == currX){
                // The index 'b' of this building in 'buildings'
                int b = edges[idx][1];
                
                // If this is a left edge of building 'b', we
                // add (height, right) of building 'b' to 'live'.
                if (buildings[b][0] == currX){
                    int right = buildings[b][1];
                    int height = buildings[b][2];
                    live.push({height, right});
                }
                idx += 1;
            }
            
            // If the tallest live building has been passed,
            // we remove it from 'live'.
            while (!live.empty() && live.top().second <= currX)
                live.pop();
            
            // Get the maximum height from 'live'.
            int currHeight = live.empty() ? 0 : live.top().first;
            
            // If the height changes at 'currX', we add this
            // skyline key point [currX, max_height] to 'answer'.
            if (answer.empty() || answer[answer.size() - 1][1] != currHeight)
                answer.push_back({currX, currHeight});
        }
        
        // Return 'answer' as the skyline.
        return answer;
    }
};