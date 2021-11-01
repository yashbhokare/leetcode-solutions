class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        vector<vector<int>> result;
        for(int i=0;i<points.size();i++){
            int dist = (pow(points[i][0],2) + pow(points[i][1],2));
            if(pq.size() == k && pq.top().first > dist){
                pq.pop();
            } else if(pq.size() == k && pq.top().first <= dist){
                continue;
            }
            pq.push({dist,i});
            // cout<<pq.top().first<<endl;
            // cout<<dist<<endl;
        }
        
        for(int i=0;i<k;i++){
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        return result;
        
    }
};