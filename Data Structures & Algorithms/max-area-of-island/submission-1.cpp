class Solution {
public:
    struct Coords {
        int r;
        int c;

        Coords(int _r, int _c) {
            r = _r;
            c = _c;
        }
    };

    int _rows;
    int _cols;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        _rows = grid.size();
        _cols = grid[0].size();
        int maxArea = 0;
        for (int r = 0; r < _rows; ++r) {
            for (int c = 0; c < _cols; ++c) {
                if (grid[r][c] == 0) { continue; }

                // cout << "Land found at " << r << ", " << c << "\n";
                Coords coords(r, c);
                maxArea = max(maxArea, dfs(grid, coords));
            }
        }
        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, Coords& coords) {
        // cout << "Inside dfs()\n";
        int size = 0;

        // Mark current square as visited
        grid[coords.r][coords.c] = 0;
        size++;

        queue<Coords> q;
        q.push(coords);

        Coords offsets[4] = {{0,1}, {1,0}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            auto coords = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                Coords cur(coords.r + offsets[i].r, coords.c + offsets[i].c);

                // cout << "Checking land to the ";
                // if (i == 0) {
                //     cout  << "East\n";
                // } else if (i == 1) {
                //     cout << "South\n";
                // } else if (i == 2) {
                //     cout << "North\n";
                // } else {
                //     cout << "West\n";
                // }

                if (cur.r < 0 || cur.r >= _rows || cur.c < 0 || cur.c >= _cols || grid[cur.r][cur.c] == 0) {
                    continue;
                }

                // Add this element and mark as visited
                q.push(cur);
                grid[cur.r][cur.c] = 0;
                size++;
            }
        }

        return size;
    }
};
