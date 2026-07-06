class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;

    TimeMap() { }

    // O(1)
    void set(string key, string value, int timestamp) 
    {
        mp[key].push_back({value, timestamp});
    }
    
    // O(logn)
    string get(string key, int timestamp) 
    {
        if (mp.find(key) == mp.end()) { return ""; }

        vector<pair<string, int>>& values = mp[key];
        int l = 0, r = values.size() - 1;

        string closest;
        while (l <= r)
        {
            int m = (l + r) / 2;
            int midTimestamp = values[m].second;

            if (timestamp > midTimestamp)
            {
                // Since timestamp we are looking for is greater than
                // midTimestamp this could be the closest we get
                closest = values[m].first;
                l = m + 1;
            }
            else if (timestamp == midTimestamp)
            {
                return values[m].first;
            }
            else // timestamp < midTimestamp
            { 
                r = m - 1;
            }
        }

        return closest;
    }
};
