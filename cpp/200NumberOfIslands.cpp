class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        deque<pair<int, int>> dq;
        int height = grid.size();
        int width = grid[0].size();

        int numIslands = 0;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1') {
                    dq.push_back({i, j});
                    numIslands++;
                }

                while (!dq.empty()) {
                    pair<int, int> coords = dq.front();

                    if (coords.second < 0 || coords.second >= width || coords.first < 0 || coords.first >= height || grid[coords.first][coords.second] == '0') {
                        dq.pop_front();
                        continue;
                    } else {
                        grid[coords.first][coords.second] = '0';
                        dq.push_back({coords.first + 1, coords.second});
                        dq.push_back({coords.first - 1, coords.second});
                        dq.push_back({coords.first, coords.second + 1});
                        dq.push_back({coords.first, coords.second - 1});
                    }
                }
            }
        }

        return numIslands;
    }
};
