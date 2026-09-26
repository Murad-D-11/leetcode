class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix[0].size() - 1;
        int middle = high / 2;

        // find the row that target is an element of
        int lowRow = 0;
        int highRow = matrix.size() - 1;
        int middleRow = highRow / 2;

        while (lowRow <= highRow) {
            middleRow = lowRow + ((highRow - lowRow) / 2);

            if (matrix[middleRow][low] > target) highRow = middleRow - 1;
            else if (matrix[middleRow][high] < target) lowRow = middleRow + 1;
            else break;
        }

        // binary search
        while (low <= high) {
            middle = low + ((high - low) / 2);

            if (matrix[middleRow][middle] < target) low = middle + 1;
            else if (matrix[middleRow][middle] > target) high = middle - 1;
            else return true;
        }

        return false;
    }
};
