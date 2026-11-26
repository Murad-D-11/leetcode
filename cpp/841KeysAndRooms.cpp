class Solution {
public:
    vector<bool> visitedRooms;

    void dfs(vector<vector<int>>& rooms, int room) {
        visitedRooms[room] = true;

        for (int key : rooms[room]) {
            if (!visitedRooms[key]) dfs(rooms, key);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visitedRooms.assign(rooms.size(), false);
        dfs(rooms, 0);

        for (int i = 0; i < rooms.size(); i++) {
            if (!visitedRooms[i]) return false;
        }

        return true;
    }
};
