class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFrequency;
        for (int i = 0; i < nums.size(); ++i) { numFrequency[nums[i]]++; }

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        for (auto [key, value] : numFrequency) {
            pq.push({value, key});
        }

        vector<int> r;
        for (int i = 0; i < k; ++i) {
            r.push_back(pq.top().second);
            pq.pop();
        }
        return r;
    }
};
