class MyHashSet {
public:
    vector<int> hSet;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bool found = false;
        for (int i = 0; i < hSet.size(); ++i)
        {
            if (hSet[i] == key)
            {
                found = true;
            }
        }

        if (!found) hSet.push_back(key);
    }
    
    void remove(int key) {
        hSet.erase(std::remove(hSet.begin(), hSet.end(), key), hSet.end());
    }
    
    bool contains(int key) {
        bool found = false;
        for (int i = 0; i < hSet.size(); ++i)
        {
            if (hSet[i] == key)
            {
                found = true;
            }
        }

        return found;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */