class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> keyItMap;
    list<pair<int, int>> keyValList; // back is LRU
    int cap;
    int size;

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
    }

    void updateLRU(int key)
    {
        auto it = keyItMap[key];
        pair<int, int> entryCopy = *it;

        keyValList.erase(it);
        keyItMap.erase(key);
       
        // Insert element into list again and set
        // hash map iterator to front element
        keyValList.push_front(entryCopy);
        keyItMap[key] = keyValList.begin();
    }
    
    int get(int key) {
        if (keyItMap.find(key) != keyItMap.end())
        {
            updateLRU(key);
            return (*keyItMap[key]).second;
        }
        return -1;
    }

    void put(int key, int value) {
        // If key already in cache, update values
        if (keyItMap.find(key) != keyItMap.end())
        {
            // Update value and update LRU
            (*keyItMap[key]).second = value;
            updateLRU(key);
        }
        else if (size == cap) 
        {
            // Evict the back one (LRU)
            pair<int, int> evictedEntry = keyValList.back();
            keyValList.pop_back();
            keyItMap.erase(evictedEntry.first);

            // Push an entry to the front
            pair<int, int> newEntry;
            newEntry.first = key;
            newEntry.second = value;
            keyValList.push_front(newEntry);
            keyItMap[key] = keyValList.begin();
        }
        else
        {
            // There is space
            size++;
            // Push an entry to the front
            pair<int, int> newEntry;
            newEntry.first = key;
            newEntry.second = value;
            keyValList.push_front(newEntry);
            keyItMap[key] = keyValList.begin();
        }
    }
};
