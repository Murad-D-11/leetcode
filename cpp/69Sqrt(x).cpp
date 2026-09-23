class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        long middle = x / 2;    // <--- using long instead of int to bypass int overflow

        while (low <= high) {
            middle = low + ((high - low) / 2);

            if (middle * middle > x) high = middle - 1;
            else if (middle * middle < x) low = middle + 1;
            else return middle; 
        }

        if (middle * middle > x) return middle - 1;
        else return middle;
    }
};
