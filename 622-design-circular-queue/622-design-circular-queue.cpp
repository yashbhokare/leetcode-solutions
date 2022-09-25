class MyCircularQueue {
public:
    vector<int> dq;
    int size;
    int head= -1;
    int tail = -1;
    MyCircularQueue(int k) {
        dq.resize(k);
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        if(tail==-1){
            head=0;
        }
        tail = (tail+1)%size;
        dq[tail]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(head==tail){
            tail=-1;
            head=-1;
            return true;
        }
        head = (head+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return dq[head];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return dq[tail];
    }
    
    bool isEmpty() {
        if(head==-1 && tail==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(((tail+1)%size)==head) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */