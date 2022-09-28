class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(auto interval:intervals){
            if(min_heap.empty() || min_heap.top()>interval[0]){
                min_heap.push(interval[1]);
            }else {
                min_heap.pop();
                min_heap.push(interval[1]);
            }
        }
        return min_heap.size();
    }
};