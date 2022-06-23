class Solution {
public:
    static int comparator(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comparator);
        priority_queue<int> maxHeap;
        int total = 0;
        for(auto course:courses){
            int startTime = course[0];
            int endTime = course[1];
            if(total+startTime<=endTime){
                total = total + startTime;
                maxHeap.push(startTime);
            }else if(!maxHeap.empty() && maxHeap.top() > startTime){
                total = total -  maxHeap.top();
                maxHeap.pop();
                total = total + startTime;
                maxHeap.push(startTime);
            }
        }
        return maxHeap.size();
    }
};