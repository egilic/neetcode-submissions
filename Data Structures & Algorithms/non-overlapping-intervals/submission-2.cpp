class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (size_t i = 0; i < intervals.size(); ++i) {
            pair p{intervals[i][0], intervals[i][1]};
            pq.push(p);
        }

        int num_erased = 0;
        auto cur = pq.top();
        pq.pop();
        int prev_end = cur.second;
        while (!pq.empty()) {
            auto next = pq.top();
            pq.pop();

            if (next.first < prev_end) {
                /* Overlapping */
                num_erased++;
                prev_end = min(prev_end, next.second);
            } else {
                /* Non-overlapping */
                prev_end = next.second;
            }
        }
        return num_erased;
    }
};
