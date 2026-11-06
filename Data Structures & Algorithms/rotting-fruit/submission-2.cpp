class Solution {
public:
    struct Coords {
        int r;
        int c;
    };

    int rows;
    int cols;
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        /*
            dfs (queue)

            2d matrix of the current condition

            num fruit counter
        */

        vector<vector<bool>> checked(rows, vector<bool>(cols, false));
        int num_fruit = 0;

        queue<Coords> q;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) { num_fruit++; }

                if (grid[r][c] == 2) { 
                    q.push(Coords{r, c}); 
                    checked[r][c] = true;
                }

                if (grid[r][c] == 0) {
                    checked[r][c] = true;
                }
            }
        }
        if (num_fruit == 0) { return 0; }

        int num_mins = -1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                Coords c = q.front();
                q.pop();

                checkAndPush(q, c, checked, grid, num_fruit);
            }
            num_mins++;
            cout << "sz = " << sz << " and num_mins=" << num_mins << "\n";
        }
        if (num_fruit == 0) {
            return num_mins;
        } else {
            return -1;
        }
    }

    void checkAndPush(queue<Coords>& q, Coords& cur, vector<vector<bool>>& checked, vector<vector<int>>& grid, int& num_fruit) {
        // North
        int c = cur.c;
        int r = cur.r;
        if (r != 0) {
            if (grid[r-1][c] == 1 && !checked[r-1][c]) {
                q.push(Coords{r-1, c});
                checked[r-1][c] = true;
                num_fruit--;
            }
        }

        // South
        if (r != rows - 1) {
            if (grid[r+1][c] == 1 && !checked[r+1][c]) {
                q.push(Coords{r+1, c});
                checked[r+1][c] = true;
                num_fruit--;
            }
        }

        // East
        if (c != cols - 1) {
            if (grid[r][c+1] == 1 && !checked[r][c+1]) {
                q.push(Coords{r, c+1});
                checked[r][c+1] = true;
                num_fruit--;
            }
        }

        // West
        if (c != 0) {
            if (grid[r][c-1] == 1 && !checked[r][c-1]) {
                q.push(Coords{r, c-1});
                checked[r][c-1] = true;
                num_fruit--;
            }
        }
    }
};
