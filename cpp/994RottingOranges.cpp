class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int, int>> dq;
        int width = grid[0].size();
        int height = grid.size();

        int minutes = -1;
        int fresh = 0;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                    fresh++;
                    dq.push_back({i, j});
                } else if (grid[i][j] == 1) fresh++;
            }
        }

        while (!dq.empty() && fresh > 0) {
            int layerSize = dq.size();

            while (layerSize != 0) {
                pair<int, int> coords = dq.front();
                dq.pop_front();
                layerSize--;

                if (coords.first < 0 || coords.second < 0 || coords.first >= height || coords.second >= width || grid[coords.first][coords.second] != 1) {
                    continue;
                }

                grid[coords.first][coords.second] = 2;
                fresh--;
                dq.push_back({coords.first + 1, coords.second});
                dq.push_back({coords.first - 1, coords.second});
                dq.push_back({coords.first, coords.second + 1});
                dq.push_back({coords.first, coords.second - 1});
            }

            minutes++;
        }

        return (fresh > 0) ? -1 : max(minutes, 0);
    }
};
