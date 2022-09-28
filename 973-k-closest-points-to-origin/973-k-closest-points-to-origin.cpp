class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> max_heap;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            double val = sqrt(pow(x,2)+pow(y,2));
            max_heap.push({val,i});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        vector<vector<int>> result;
        while(!max_heap.empty()){
            result.push_back(points[max_heap.top().second]);
            max_heap.pop();
        }
        return result;
    }
};