class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) { // <-- i + 1 ignores the diagonals
                swap(matrix[i][j], matrix[j][i]); // transpose rows to columns
            }
        }

        int reverseCount;

        for (int i = 0; i < matrix.size(); i++) {
            reverseCount = matrix.size() - 1;
            for (int j = 0; j < matrix.size() / 2; j++) { // <--- matrix.size() swap until you get to midpoint, otherwise will undo the reverse
                swap(matrix[i][j], matrix[i][reverseCount]); // reverses elements
                reverseCount--;
            }
        }
    }
};
