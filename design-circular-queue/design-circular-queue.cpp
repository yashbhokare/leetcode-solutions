class MyCircularQueue {
private:
    vector<int> cQueue;
    int head=-1,tail=-1,n;
public:
    MyCircularQueue(int k) {
        cQueue.resize(k);
        head=-1;
        tail=-1;
        n=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){ head++;}
        tail++;
        tail=tail%n;
        cQueue[tail]=value;
        return true;
    }
    
    bool deQueue() {
         if(isEmpty()){
           return false;
        }
        if(head==tail){
            head=-1;
            tail=-1;
            return true;
        }        
        head++;
        head=head%n;
        return true;
        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return cQueue[head];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return cQueue[tail];
    }
    
    bool isEmpty() {
        if(head==-1 && tail==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(head==(tail+1)%n) return true;
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