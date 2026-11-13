class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        deque<pair<int, int>> dq;
        int height = grid.size();
        int width = grid[0].size();

        int perimeter = 0;
        bool found = false;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++)
                if (grid[i][j] == 1) {
                    dq.push_back({i, j});
                    found = true;
                    break;
                }
            
            if (found) break;
        }   
            

        while (!dq.empty()) {
            pair<int, int> coords = dq.front();

            if (coords.first < 0 || coords.second < 0 || coords.first >= height || coords.second >= width || grid[coords.first][coords.second] == 0) {
                perimeter++;
                dq.pop_front();
                continue;
            } else if (grid[coords.first][coords.second] == -1) {
                dq.pop_front();
                continue;
            } else {
                dq.pop_front();
                grid[coords.first][coords.second] = -1;
                dq.push_back({coords.first + 1, coords.second});
                dq.push_back({coords.first - 1, coords.second});
                dq.push_back({coords.first, coords.second + 1});
                dq.push_back({coords.first, coords.second - 1});
            }
        }
        
        return perimeter;
    }
};
