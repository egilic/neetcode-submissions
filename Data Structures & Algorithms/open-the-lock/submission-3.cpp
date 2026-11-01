class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend_set;
        unordered_set<string> visited;
        for (auto s : deadends) { deadend_set.insert(s); }

        string current = "0000";

        if (current == target) {
            return 0;
        } else if (deadend_set.contains(current)) {
            return -1;
        }



        queue<string> locks;
        locks.push(current);
        visited.insert(current);

        int num_turns = 0;
        while (!locks.empty()) {
            int sz = locks.size();

            for (int i = 0; i < sz; ++i) {
                current = locks.front();
                locks.pop();

                // Try to add all combinations of these locks
                for (int j = 0; j < 4; ++j) {
                    string up = current;
                    if (current[j] == '9') {
                        up[j] = '0';
                    } else {
                        up[j] = current[j] + 1;
                    }

                    if (deadend_set.contains(up) || visited.contains(up)) {

                    } else if (up == target) {
                        num_turns++;
                        return num_turns;
                    } else {
                        locks.push(up);
                        visited.insert(up);
                    }
                    
                    string down = current;
                    if (current[j] == '0') {
                        down[j] = '9';
                    } else {
                        down[j] = current[j] - 1;
                    }

                    if (deadend_set.contains(down)) { continue; }
                    if (visited.contains(down)) { continue; }
                    if (down == target) {
                        num_turns++;
                        return num_turns;
                    }
                    
                    locks.push(down);
                    visited.insert(down);
                } // for 'j'
            }
            num_turns++;
        }
        return -1;
    }
};