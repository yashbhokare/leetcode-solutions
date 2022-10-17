class MyCalendar {
public:
    map<int,int> mapper;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int count = 0;
        mapper[start]++;
        mapper[end]--;
        for(auto val:mapper){
            count+=val.second;
            if(count>1){
                mapper[start]--;
                mapper[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */