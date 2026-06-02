class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minpq;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto num : nums)
        {
            if (minpq.size() < k)
            {
                minpq.push(num);
            }
            else {
                if (minpq.top() < num)
                {
                    minpq.pop();
                    minpq.push(num);
                }
            }
        }
    }
    
    int add(int val) {
        if (minpq.size() == _k && minpq.top() < val)
        {
            minpq.pop();
            minpq.push(val);
        }
        if (minpq.size() < _k) {
            minpq.push(val);
        }
        return minpq.top();
    }
};
