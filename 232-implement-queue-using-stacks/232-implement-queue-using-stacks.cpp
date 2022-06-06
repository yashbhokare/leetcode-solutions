class MyQueue {
public:
    stack<int> res;
    stack<int> dummy;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(empty()) res.push(x);
        else{
            while(!res.empty()){
                dummy.push(res.top());
                res.pop();
            }
            res.push(x);
             while(!dummy.empty()){
                res.push(dummy.top());
                dummy.pop();
            }
        }
    }
    
    int pop() {
        if(empty()) return -1;
        int temp=res.top();
        res.pop();
        return temp;
    }
    
    int peek() {
        return res.top();
    }
    
    bool empty() {
        return res.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */