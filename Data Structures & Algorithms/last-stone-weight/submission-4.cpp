class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto stone : stones)
        {
            pq.push(stone);
        }

        while (pq.size() > 1)
        {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            int diff = s1 - s2;
            if (diff) pq.push(diff);
        }
        
        if (pq.empty()) return 0;
        return pq.top();
    }
};
