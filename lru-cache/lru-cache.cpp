class LRUCache {
public:
    int maxCapacity;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> l;
    LRUCache(int capacity) {
        maxCapacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)== mp.end()){
            return -1;
        }
        
        l.splice(l.begin(),l,mp[key]);       
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            l.splice(l.begin(),l,mp[key]);
            mp[key]->second = value;
            return;
        }
        
        if(l.size() == maxCapacity){
            int removeKey= l.back().first;
            l.pop_back();
            mp.erase(removeKey);
        }
        
        l.push_front({key,value});
        mp.insert({key,l.begin()});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */