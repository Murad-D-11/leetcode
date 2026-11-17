class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        deque<string> dq;
        int numMoves = 0;

        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000") > 0) return -1;
        if (target == "0000") return 0;

        dq.push_back("0000");
        while (!dq.empty()) {
            numMoves++;
            int layerSize = dq.size();

            while (layerSize > 0) {
                string parent = dq.front();
                dq.pop_front();

                for (int digit = 0; digit < 4; digit++) {
                    for (int change : {-1, 1}) {
                        string child = parent;
                        child[digit] = '0' + (child[digit] - '0' + change + 10) % 10; // chars are weird
                        
                        if (child == target) return numMoves;

                        if (visited.count(child) > 0) continue;
                        visited.insert(child);
                        dq.push_back(child);
                    }
                }

                layerSize--;
            }
        }

        return -1;
    }
};
