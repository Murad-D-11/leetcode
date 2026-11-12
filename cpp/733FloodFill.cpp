class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        deque<pair<int, int>> dq;
        dq.push_back({sr, sc});

        int oldColour = image[sr][sc];
        int height = image.size();
        int width = image[0].size();

        if (oldColour == color) return image;

        while (!dq.empty()) {
            pair<int, int> coords = dq.front();
            
            if (coords.first < 0 || coords.second < 0 || coords.first >= height || coords.second >= width || oldColour != image[coords.first][coords.second]) { 
                dq.pop_front();
                continue;
            } else {
                image[coords.first][coords.second] = color;
                dq.pop_front();

                dq.push_back({coords.first, coords.second - 1});
                dq.push_back({coords.first, coords.second + 1});
                dq.push_back({coords.first - 1, coords.second});
                dq.push_back({coords.first + 1, coords.second});
            }
        }

        return image;
    }
};
