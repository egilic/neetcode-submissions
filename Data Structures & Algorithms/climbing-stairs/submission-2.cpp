class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int,int> cache;
        int res = memo(n, n, cache);
        return res;
    }

    int memo(int n, int sum, unordered_map<int,int>& cache)
    {
        if (sum < 0)
        {
            return 0;
        }
        else if (sum == 1)
        {
            return 1;
        }
        else if (sum == 2)
        {
            return 2;
        }

        if (cache.contains(sum))
        {
            return cache[sum];
        }
        
        cache[sum] = memo(n, sum - 1, cache) + memo(n, sum - 2, cache);
        return cache[sum];
    }
};
