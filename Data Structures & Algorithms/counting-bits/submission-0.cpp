class Solution {
public:
    vector<int> countBits(int n) {
        int MAX_VALUE = 1000;
        int maxOnes = ceil(log2(MAX_VALUE));
        vector<int> r{};
        r.resize(n + 1);
        r[0] = 0;
        
        for (int i = 1; i <= n; ++i) 
        {
            int numOnes = 0;
            int mask = 1;
            for (int j = 0; j < maxOnes; ++j)
            {
                if (i & mask)
                {
                    numOnes++;
                }
                mask = (mask << 1);
            }
            r[i] = numOnes;
        }

        return r;
    }
};
