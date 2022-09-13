class MyCalendar {
private:
    set<pair<int,int>> calendar;
    

public:
    bool book(int start, int end) {
        
        pair<int,int> newEvent = {start,end};
        
        auto it = calendar.lower_bound(newEvent);
        
        if(it!=calendar.end() && end>it->first){
            return false;
        }
        
        if(it!=calendar.begin()){
            auto prevEvent= prev(it);
            if(start< prevEvent->second) return false;
        }
        
        calendar.insert(newEvent);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */