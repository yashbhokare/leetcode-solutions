class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int minStops=0;
        int currentStationIndex = 0;
        int totalStations = size(stations);
        while(startFuel<target)
        {
            while(currentStationIndex < totalStations and stations[currentStationIndex][0]<=startFuel)
            {
                pq.push(stations[currentStationIndex][1]);
                currentStationIndex++;
            }
            if(pq.empty())
                return -1;
            startFuel+=pq.top();
            pq.pop();
            minStops++;
        }
        return minStops;
    }
};

//https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/1266490/Minimum-Number-of-Refueling-Stops-or-Greedy-or-PriorityQueue