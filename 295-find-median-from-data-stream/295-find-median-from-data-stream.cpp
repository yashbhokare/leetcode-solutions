class MedianFinder {
    priority_queue<int> maxLeft;
    priority_queue<int,vector<int>,greater<int>> minRight;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxLeft.push(num);
        minRight.push(maxLeft.top());maxLeft.pop();
        if(maxLeft.size()<minRight.size()){
            maxLeft.push(minRight.top()); minRight.pop();
        }
    }
    
    double findMedian() {
        if(maxLeft.size()==minRight.size()){
            return (minRight.top()+maxLeft.top())/2.0;
        }else {
            return maxLeft.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */