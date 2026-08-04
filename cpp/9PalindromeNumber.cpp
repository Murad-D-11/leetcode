class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        // find the greatest power-of-ten divisor
        int divisorLtoR = 10;
        while (x / divisorLtoR >= 10) {
            divisorLtoR *= 10;
        }

        // compare the two digits
        int xRtoL = x;
        int xLtoR = x;
        while (divisorLtoR >= 10) {
            if ((xLtoR / divisorLtoR) != (xRtoL % 10)) {
                return false;
            }

            xLtoR %= divisorLtoR;
            xRtoL /= 10;

            divisorLtoR /= 10;
        }

        return true;
    }
};
