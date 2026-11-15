class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        deque<pair<int, int>> dq;
        int height = grid.size();
        int width = grid[0].size();

        int distance = 1;

        dq.push_back({0, 0});
        while (!dq.empty()) {
            int layerSize = dq.size();
            
            while (layerSize > 0) {
                pair<int, int> coords = dq.front();
                
                if (coords.first < 0 || coords.second < 0 || coords.first >= height || coords.second >= width || grid[coords.first][coords.second] != 0) {
                    dq.pop_front();
                } else if (coords.first == height - 1 && coords.second == width - 1) {
                    return distance;
                } else {
                    grid[coords.first][coords.second] = -1;
                    dq.pop_front();

                    dq.push_back({coords.first + 1, coords.second + 1});
                    dq.push_back({coords.first + 1, coords.second - 1});
                    dq.push_back({coords.first - 1, coords.second + 1});
                    dq.push_back({coords.first - 1, coords.second - 1});
                    dq.push_back({coords.first + 1, coords.second});
                    dq.push_back({coords.first - 1, coords.second});
                    dq.push_back({coords.first, coords.second + 1});
                    dq.push_back({coords.first, coords.second - 1});
                }

                layerSize--;
            }

            distance++;
        }

        return -1;
    }
};
