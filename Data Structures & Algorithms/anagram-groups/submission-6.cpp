class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> r;
        for (auto& s : strs)
        {
            vector<int> key(26, 0);
            for (int i = 0; i < s.length(); ++i)
            {
                key[s[i] - 'a']++;
            }
            mp[key].push_back(s);
        }
        for (const auto& [key, value] : mp)
        {
            r.push_back(value);
        }
        return r;
    }
};
