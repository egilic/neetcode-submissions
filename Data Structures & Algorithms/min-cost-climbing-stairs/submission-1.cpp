class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> stairCostMp;
        return min(memo(cost, stairCostMp, 0), memo(cost, stairCostMp, 1));
    }

    int memo(vector<int>& cost, unordered_map<int, int>& stairCostMp, int stair)
    {
        if (stair >= cost.size())
        {
            return 0;
        }

        if (stairCostMp.contains(stair))
        {
            return stairCostMp[stair];
        }
        else
        {
            stairCostMp[stair] = cost[stair] + min(memo(cost, stairCostMp, stair + 1), memo(cost, stairCostMp, stair + 2));
            return stairCostMp[stair];
        }
    }
};
