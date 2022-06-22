class TimeMap {
public:
    
    unordered_map<string,map<int,string>> mapper;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
            mapper[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it = mapper[key].upper_bound(timestamp);
        return it == mapper[key].begin() ? "" : prev(it)->second;
        // display(key,timestamp);
        if(mapper.find(key)==mapper.end()) return "";
        auto setMap = mapper[key];
        if(setMap.find(timestamp)==setMap.end()) return minElement(key,timestamp);
        else return setMap[timestamp];
    }
    
    void display(string key, int timestamp){
        if(mapper.find(key)==mapper.end()) cout<<"Not Found"<<endl;
        auto setMap = mapper[key];
        for(auto it=setMap.begin();it!=setMap.end();it++){
            cout<<"Key:"<<key<<" Timestamp:"<<it->first<<" Value:"<<it->second<<endl;
        }
    }
    
    string minElement(string key, int timestamp){
        auto setMap = mapper[key];
        for(auto it=setMap.rbegin();it!=setMap.rend();it++){
            if(it->first<timestamp) return it->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */