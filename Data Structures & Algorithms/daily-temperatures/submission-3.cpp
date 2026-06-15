class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        vector<int> dailyTemps(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i)
        {
            if (s.empty() || (!s.empty() && s.top().first > temperatures[i]))
            {
                s.push({temperatures[i], i});
            } 
            else
            {
                // Greater temp found
                while (!s.empty() && s.top().first < temperatures[i])
                {
                    auto tmpIndexPair = s.top();
                    s.pop();

                    dailyTemps[tmpIndexPair.second] = (i - tmpIndexPair.second);
                }
                s.push({temperatures[i], i});
            }
        }
        return dailyTemps;
    }
};
