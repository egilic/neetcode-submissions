class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_intervals;

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> min_heap;
        if (intervals.empty()) { return merged_intervals; } 
        if (intervals.size() == 1) {
            vector<int> tmp {intervals[0][0], intervals[0][1]};
            merged_intervals.push_back(tmp);
            return merged_intervals;
        }

        /* create pq */
        for (auto& vec : intervals) {
            pair p{vec[0], vec[1]};
            min_heap.push(p);
        }

        auto cur_pair = min_heap.top();
        min_heap.pop();

        while (!min_heap.empty()) {
            auto next_pair = min_heap.top();
            min_heap.pop();

            if (next_pair.first <= cur_pair.second) {
                cur_pair.second = max(cur_pair.second, next_pair.second);

                if (min_heap.empty()) {
                    vector<int> tmp {cur_pair.first, cur_pair.second};
                    merged_intervals.push_back(tmp);
                }
            } else {
                vector<int> tmp {cur_pair.first, cur_pair.second};
                merged_intervals.push_back(tmp);
                cur_pair = next_pair;

                if (min_heap.empty()) {
                    vector<int> tmp {cur_pair.first, cur_pair.second};
                    merged_intervals.push_back(tmp);
                }
            }
        }

        return merged_intervals;
    }
};
