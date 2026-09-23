class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        long middle = high / 2;

        while (low <= high) {
            middle = low + ((high - low) / 2);

            if (middle * middle < num) low = middle + 1;
            else if (middle * middle > num) high = middle - 1;
            else return true;
        }

        return false;
    }
};
