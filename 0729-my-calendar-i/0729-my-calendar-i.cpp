// class MyCalendar {
// public:
//     map<int,int> mapper;
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {
//         int count = 0;
//         mapper[start]++;
//         mapper[end]--;
//         for(auto val:mapper){
//             count+=val.second;
//             if(count>1){
//                 mapper[start]--;
//                 mapper[end]++;
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class MyCalendar {
private:
    set<pair<int,int>> calendar;
    

public:
    bool book(int start, int end) {
        
        const pair<int,int> currEvent = {start,end};
        
        const auto nextEvent = calendar.lower_bound(currEvent);
        
        if(nextEvent!=calendar.end() && end > nextEvent->first){
            return false;
        }
        
        if(nextEvent!=calendar.begin()){
            auto prevEvent= prev(nextEvent);
            if(start< prevEvent->second) return false;
        }
        
        calendar.insert(currEvent);
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */