class MinStack {
public:
    stack<int> s;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min.empty() || val<=min.top()){
            min.push(val);
        }
    }
    
    void pop() {
        int val = s.top();
        if(val == min.top()){
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */