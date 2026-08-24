class Solution {
public:
    vector<vector<int>> triangle;

    long long factorial(int n) {
        long long product = 1;

        for (int i = n; i > 1; i--) {
            product *= i;
        }

        return product;
    }

    vector<vector<int>> generate(int numRows) {
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                row.push_back((factorial(i)) / (factorial(j) * factorial(i - j)));
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};
