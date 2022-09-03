class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return 1; 
        priority_queue<int,vector<int>,greater<int>> minHeap;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(minHeap.size() == 0 || minHeap.top() > intervals[i][0]){
                minHeap.push(intervals[i][1]);
            }else {
                minHeap.pop();
                minHeap.push(intervals[i][1]);
            }
        }
        return minHeap.size();
    }
};