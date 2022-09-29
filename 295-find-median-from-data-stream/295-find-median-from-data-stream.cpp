class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap; // Min Element on top
    priority_queue<int> maxHeap; // Max element on top
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // Add element to max heap
        maxHeap.push(num);
        // Add the top element to min heap
        minHeap.push(maxHeap.top());maxHeap.pop();
        
        if(minHeap.size()>maxHeap.size()){
            // Add the min element to the top of max heap
             maxHeap.push(minHeap.top());minHeap.pop();
        }
        
        
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }else {
            return maxHeap.top();
        }
         
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */