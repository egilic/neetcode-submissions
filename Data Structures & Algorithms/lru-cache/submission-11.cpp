class LRUCache {
public:
    int cap;
    int sz; 
    unordered_map<int, list<pair<int, int>>::iterator> cache;

    // LRU is at the back
    list<pair<int, int>> lru;

    LRUCache(int capacity) {
        cap = capacity;
        sz = 0;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) 
        {
            pair<int, int> kv = *cache[key];
            int k = kv.first;
            int v = kv.second;

            lru.erase(cache[k]);
            cache.erase(k);
   
            lru.push_front({k,v});
            cache[k] = lru.begin();

            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // At capacity but this one alr exists
            pair<int, int> p = *cache[key];
            lru.erase(cache[key]);
            cache.erase(key);
        } else if (sz == cap) {
            // Evict
            pair<int, int> p = lru.back();
            int k = p.first;
            int v = p.second;
            cache.erase(k);
            lru.pop_back();
        } else {
            sz++;
        }


        lru.push_front({key, value});
        cache[key] = lru.begin();
    }
};
