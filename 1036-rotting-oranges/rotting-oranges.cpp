
class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        // Step 1: Insert all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Step 2: Multi-source BFS
        while (!q.empty() && fresh > 0) {

            int s = q.size();
            time++;

            while (s--) {

                pair<int, int> p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                // Check all 4 directions
                for (int k = 0; k < 4; k++) {

                    int row = r + x[k];
                    int col = c + y[k];

                    if (valid(row, col, n, m) &&
                        grid[row][col] == 1) {

                        q.push({row, col});
                        grid[row][col] = 2;
                        fresh--;
                    }
                }
            }
        }

        if (fresh > 0)
            return -1;

        return time;
    }
};
