struct Cache {
    int _key, _value;
    Cache(int key, int value) : _key(key), _value(value) {}
};

class LRUCache {
    list<Cache> cache;
    map<int, list<Cache>::iterator> pos;
    int _cap;

public:
    LRUCache(int capacity) : _cap(capacity) {}
    
    int get(int key) {
        if(pos.find(key) == pos.end()) return -1;
        auto it = pos[key];
        cache.push_front(*it);
        cache.erase(it);
        pos[key] = cache.begin();
        return pos[key]->_value;
    }
    
    void put(int key, int value) {
        if(pos.find(key) == pos.end()) {
            cache.push_front(Cache(key, value));
            pos[key] = cache.begin();
            if(cache.size() > _cap) {
                Cache lastNode = cache.back();
                pos.erase(lastNode._key);
                cache.pop_back();
            }
        } else {
            auto it = pos[key];
            it->_value = value;
            cache.push_front(*it);
            cache.erase(it);
            pos[key] = cache.begin();
        }
    }
};
