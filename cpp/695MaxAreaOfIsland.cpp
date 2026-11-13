class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        deque<pair<int, int>> dq;
        int height = grid.size();
        int width = grid[0].size();

        int maxIslandArea = 0;
        int currIslandArea;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1) { 
                    dq.push_back({i, j});
                    currIslandArea = 0;
                }
                
                while (!dq.empty()) {
                    pair<int, int> coords = dq.front();
                    
                    if (coords.first < 0 || coords.second < 0 || coords.first >= height || coords.second >= width || grid[coords.first][coords.second] == 0) {
                        dq.pop_front();
                        continue;
                    } else {
                        grid[coords.first][coords.second] = 0;
                        dq.push_back({coords.first + 1, coords.second});
                        dq.push_back({coords.first - 1, coords.second});
                        dq.push_back({coords.first, coords.second + 1});
                        dq.push_back({coords.first, coords.second - 1});
                        
                        currIslandArea++;
                    }
                }

                maxIslandArea = max(maxIslandArea, currIslandArea);
            }
        }

        return maxIslandArea;
    }
};
