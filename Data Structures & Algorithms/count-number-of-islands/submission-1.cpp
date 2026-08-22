class Solution {
public:
    int cols_;
    int rows_;
    struct Coords {
        int r;
        int c;
    };

    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        cols_ = cols;
        rows_ = rows;
        vector<vector<bool>> discovered;
        discovered.resize(rows);
        for (auto& row : discovered) {
            row.resize(cols, false); 
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '0' || discovered[r][c] == true) { continue; }
                else {
                    // perform dfs to loop through and check NESW and increment num_islands
                    dfs(grid, discovered, r, c);
                    num_islands++;
                }
            }
        }

        return num_islands;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& discovered, int r, int c) {
        queue<Coords> q;
        Coords coords = {r, c};
        q.push(coords);
        discovered[coords.r][coords.c] = true;

        while (!q.empty()) {
            Coords cur = q.front();
            q.pop();

            // north
            if (cur.r > 0 && grid[cur.r - 1][cur.c] == '1' && !discovered[cur.r - 1][cur.c]) {
                Coords tmp = {cur.r - 1, cur.c};
                discovered[cur.r - 1][cur.c] = true;
                q.push(tmp);
            }

            // south
            if (cur.r < rows_ - 1 && grid[cur.r + 1][cur.c] == '1' && !discovered[cur.r + 1][cur.c]) {
                Coords tmp = {cur.r + 1, cur.c};
                discovered[cur.r + 1][cur.c] = true;
                q.push(tmp);
            }

            // east
            if (cur.c < cols_ - 1 && grid[cur.r][cur.c + 1] == '1' && !discovered[cur.r][cur.c + 1]) {
                Coords tmp = {cur.r, cur.c + 1};
                discovered[cur.r][cur.c + 1] = true;
                q.push(tmp);
            }

            if (cur.c > 0 && grid[cur.r][cur.c - 1] == '1' && !discovered[cur.r][cur.c - 1]) {
                Coords tmp = {cur.r, cur.c - 1};
                discovered[cur.r][cur.c - 1] = true;
                q.push(tmp);
            }
        }
    }
};
