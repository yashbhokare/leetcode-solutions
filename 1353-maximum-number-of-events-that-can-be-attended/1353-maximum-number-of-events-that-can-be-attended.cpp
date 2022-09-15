class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end());
        long result=0;
        priority_queue<long,vector<long>,greater<>> minHeap;
        int i=0;
        for(long day=1;day<=100000;day++){
            

            while(i<events.size() && events[i][0]==day){
                minHeap.push(events[i][1]);
                i++;
            }
            
            while(!minHeap.empty() && minHeap.top()<day){
                minHeap.pop();
            }
            //Attend the event on given day 
            if(!minHeap.empty()){
                minHeap.pop();
                result++;
            }
            
        }
        return result;
    }
};