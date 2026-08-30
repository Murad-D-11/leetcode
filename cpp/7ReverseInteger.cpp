class Solution {
public:
    long long reverseX = 0;

    int reverse(int x) {
        while (x != 0) {
            reverseX = (reverseX * 10) + (x % 10);
            x /= 10;

            if (reverseX > INT_MAX || reverseX < INT_MIN) return 0;
        }

        return static_cast<int>(reverseX);
    }
};
