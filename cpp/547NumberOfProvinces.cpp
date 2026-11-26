class Solution {
public:
    vector<bool> visitedCities;

    void dfs(vector<vector<int>>& isConnected, int city) {
        visitedCities[city] = true;

        for (int connection = 0; connection < isConnected[city].size(); connection++) {
            if (isConnected[city][connection] == 1 && !visitedCities[connection]) {
                dfs(isConnected, connection);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numProvinces = 0;
        visitedCities.assign(isConnected.size(), false);
        
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visitedCities[i]) {
                numProvinces++;
                dfs(isConnected, i);
            }
        }

        return numProvinces;
    }
};
