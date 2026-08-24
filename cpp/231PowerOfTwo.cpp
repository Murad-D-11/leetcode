class Solution {
public:
    long base = 2;

    void raise(int n) {
        if (base >= n) {
            return;
        }

        base *= 2;
        raise(n);
    }

    bool isPowerOfTwo(int n) {
        raise(n);
        
        // base cases
        if (n == 1) return true;
        if (n < 0) return false;

        if (base == n) {
            return true;
        } else {
            return false;
        }
    }
};
