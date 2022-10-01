class LRUCache {
    int size = 0;
    unordered_map<int,list<pair<int,int>>::iterator> mapper;
    list<pair<int,int>> linked_list;
public:
    
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(mapper.find(key)==mapper.end()){
            return -1;
        }else {
            auto it=mapper[key];
            linked_list.splice(linked_list.begin(),linked_list,it);
            return it->second;
        }
    }
    
    void put(int key, int value) {
       if(mapper.find(key)!=mapper.end()){
            auto it=mapper[key];
            linked_list.splice(linked_list.begin(),linked_list,it);
            it->second = value;
            return;
       }else if(mapper.size()==size){
           auto it = linked_list.back();
           mapper.erase(it.first);
           linked_list.pop_back();
       }
        linked_list.push_front({key,value});
        auto it = linked_list.begin();
        mapper[key] = it;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */