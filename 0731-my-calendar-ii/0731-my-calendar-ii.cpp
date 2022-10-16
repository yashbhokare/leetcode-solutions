class MyCalendarTwo {
public:

    map<int,int> mapper;
    MyCalendarTwo() {
        
    }
    
    bool canAdd(int n){
        int count = 0;
        for(auto entry:mapper){
            count+=entry.second;
            if(count>2) return false;
        }
        return true;
    }
    
    bool book(int start, int end) {
        mapper[start]++;
        mapper[end]--;
        if(canAdd(2)) return true;
        else {
            mapper[start]--;
            mapper[end]++;
            return false;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */