class Solution {
public:
    struct Loc {
        int r;
        int c;
        Loc(int _r, int _c) : r(_r), c(_c) {}
    };
    int rows;
    int cols;
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int perimeter = 0;
        queue<Loc> locs;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    locs.push(Loc(i, j));
                }
            }
        }

        while (!locs.empty()) {
            Loc l = locs.front();
            locs.pop();

            // Check surrounding squares
            perimeter += sumPerimeterContribution(grid, l);
        }
        return perimeter;
    }

    int sumPerimeterContribution(vector<vector<int>>& grid, Loc& l) {
        int water = 0;
        cout << "processing location r=" << l.r << " c=" << l.c << "\n";

        // North
        if (l.r == 0 || grid[l.r - 1][l.c] != 1) {
            water++;
        }

        // South
        if (l.r == rows - 1 || grid[l.r + 1][l.c] != 1) {
            water++;
        }

        // East
        if (l.c == cols - 1 || grid[l.r][l.c + 1] != 1) {
            water++;
        }

        // West
        if (l.c == 0 || grid[l.r][l.c - 1] != 1) {
            water++;
        }
        return water;
    }
};