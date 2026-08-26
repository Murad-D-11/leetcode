class Solution {
public:
    int prev1 = 0;
    int prev2 = 1;
    int current = 0;
    int counter = 1;

    void seq(int n) {
        if (counter == n) {
            return;
        }
        
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;

        counter++;
        seq(n);
    }

    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        seq(n);

        return current;
    }
};
