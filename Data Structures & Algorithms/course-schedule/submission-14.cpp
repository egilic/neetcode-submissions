class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // [a, b]  must take b if you want to take a
        unordered_map<int, vector<int>> pMap;
        for (auto& p : prerequisites) { pMap[p[0]].push_back(p[1]); }

        unordered_set<int> visited;
        unordered_set<int> completed;
        for (int i = 0; i < numCourses; ++i) {
            // We are working on course i
            visited.insert(i);

            if (!dfs(pMap, visited, completed, i)) return false;

            completed.insert(i);
            visited.erase(i);
        }
        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& pMap, unordered_set<int>&
             visited, unordered_set<int>& completed, int courseNum) {
        // For this courseNum loop through all it's prereqs
        for (int i = 0; i < pMap[courseNum].size(); ++i) {
            if (completed.find(pMap[courseNum][i]) != completed.end()) {
                continue;
            }

            if (visited.find(pMap[courseNum][i]) != visited.end()) {
                return false;
            }

            visited.insert(pMap[courseNum][i]);

            if (!dfs(pMap, visited, completed, pMap[courseNum][i])) {
                return false;
            }

            visited.erase(pMap[courseNum][i]);

        }
        completed.insert(courseNum);
        return true;
    }
};
