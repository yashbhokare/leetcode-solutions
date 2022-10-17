class MyCalendar {
private:
set<pair<int,int>> calendar;
​
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