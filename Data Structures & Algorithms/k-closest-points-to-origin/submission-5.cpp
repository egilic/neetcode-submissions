class Solution {
public:
    double findDistance(double x1, double y1)
    {
        double xdiff = pow(x1 - 0, 2);
        double ydiff = pow(y1 - 0, 2);
        return sqrt(xdiff + ydiff);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        using dist = double;
        using idx = int;
        priority_queue<pair<dist, idx>> maxHeap;

        for (int i = 0; i < points.size(); ++i)
        {
            double dist = findDistance(points[i][0], points[i][1]);
            cout << "Analzying coords " << points[i][0] << ", " << points[i][1] << "\n";
            cout << "Distance found was " << dist << "\n";
            
            if (maxHeap.size() < k)
            {
                maxHeap.push({dist, i});
                cout << "Pushed during index " << i << "\n";
            } else {
                // if dist is less than the top element, push it
                if (dist < maxHeap.top().first)
                {
                    cout << "Popped and pushed during index " << i << "\n";
                    maxHeap.pop();
                    maxHeap.push({dist, i});
                }
            }
        }

        vector<vector<int>> r;
        int size = maxHeap.size();
        for (int i = 0; i < size; ++i)
        {
            auto top = maxHeap.top();
            maxHeap.pop();

            auto j = top.second;
            r.push_back({points[j][0], points[j][1]});
        }

        return r;
    }
};
