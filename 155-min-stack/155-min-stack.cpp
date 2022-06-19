class MinStack {
public:
    stack<int> stk1;
    stack<int> stk2;
    MinStack() {
        
    }
    
    void push(int val) {
        stk1.push(val);
        if(stk2.empty() || stk2.top()>=val){
            stk2.push(val);
        }
    }
    
    void pop() {
        if(stk2.top()==stk1.top()){
            stk2.pop();
        }
        stk1.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
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