class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int max_frequency = 0;
 public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        int f =  freq[val];
        group[f].push(val);
        if(f>max_frequency){
            max_frequency = f;
        }
    }
    
    int pop() {
        int top_freq_element = group[max_frequency].top();
        group[max_frequency].pop();
        freq[top_freq_element]--;
        if(group[max_frequency].size()==0){
            max_frequency--;
        }
        return top_freq_element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */