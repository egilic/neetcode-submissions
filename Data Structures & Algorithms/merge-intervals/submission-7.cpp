class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> nonOverlapping;
        nonOverlapping.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            auto v1 = nonOverlapping.back();
            auto v2 = intervals[i];


            // These overlap
            if (v2[0] <= v1[1]) {
                vector<int> tmp;
                tmp.push_back(min(v1[0], v2[0]));
                tmp.push_back(max(v1[1], v2[1]));

                nonOverlapping.pop_back();
                nonOverlapping.push_back(tmp);
            } else {
                nonOverlapping.push_back(v2);
            }
        }

        return nonOverlapping;
    }
};
