class Solution {
public:
    vector<vector<int>> triangle;

    vector<vector<int>> generate(int numRows) {
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // fill the triangle's edges with 1's
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // formula to find the next cell's value (without nCr)
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};
