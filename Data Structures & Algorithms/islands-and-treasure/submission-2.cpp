class Solution {
public:
    int rows;
    int cols; 
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        rows = grid.size();
        cols = grid[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r,c});
                }
            }
        }

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int dist = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                pair<int,int> loc = q.front();
                q.pop();
                int r = loc.first;
                int c = loc.second;
                visited[r][c] = true;

                addLand(grid, r - 1, c, visited, q, dist);
                addLand(grid, r + 1, c, visited, q, dist);
                addLand(grid, r, c + 1, visited, q, dist);
                addLand(grid, r, c - 1, visited, q, dist);
            }
            ++dist;
        }
    }

    void addLand(vector<vector<int>>& grid, int r, int c, 
                 vector<vector<bool>>& visited, queue<pair<int,int>>& q, int dist) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] == -1 || grid[r][c] == 0) {
            return;
        }

        q.push({r,c});
        visited[r][c] = true;
        grid[r][c] = dist;
    }
};
