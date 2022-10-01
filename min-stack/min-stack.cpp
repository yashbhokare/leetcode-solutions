class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(min_stk.empty() || min_stk.top()>=val){
            min_stk.push(val);
        }
    }
    
    void pop() {
        if(stk.top()==min_stk.top()){
            min_stk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
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