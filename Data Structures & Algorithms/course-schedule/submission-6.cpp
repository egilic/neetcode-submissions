class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> coursePrereqs;
        vector<int> visited(numCourses, 0);

        for (auto& v : prerequisites) {
            coursePrereqs[v[0]].push_back(v[1]);
        }

        for (int c = 0; c < numCourses; ++c) {
            if (!dfs(c, coursePrereqs, visited)) return false;
        }
        return true;
    }

    bool dfs(int c, unordered_map<int, vector<int>>& prereqs, vector<int>& visited) {
        vector<int>& cPres = prereqs[c];
        if (visited[c] == 1) {
            return false;
        } else if (visited[c] == 2) {
            return true;
        }
        visited[c] = 1;
        for (int i = 0; i < cPres.size(); ++i) {
            if (!dfs(cPres[i], prereqs, visited)) {
                return false;
            }
        }
        visited[c] = 2;
        return true;
    }
};
