class LRUCache {
public:
    int maxCapacity;
    unordered_map<int,list<pair<int,int>>::iterator> mapper;
    list<pair<int,int>> listMap;
    LRUCache(int capacity) {
        maxCapacity=capacity;
    }
    
    int get(int key) {
        if(mapper.find(key)==mapper.end()){
            return -1;
        }
        auto it=mapper[key];
        listMap.splice(listMap.begin(),listMap,it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(mapper.find(key)!=mapper.end()){
            auto it=mapper[key];
            it->second=value;
            listMap.splice(listMap.begin(),listMap,it);
            return;
        }
        if(maxCapacity==mapper.size()){
            auto it=listMap.back();
            mapper.erase(it.first);
            listMap.pop_back();
        }
        listMap.push_front({key,value});
        mapper[key]=listMap.begin();
            
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */