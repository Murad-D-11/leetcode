class Solution {
public:
    int currentToInt(char c) {
        if (c == 'M') {
            return 1000;
        } else if (c == 'D') {
            return 500;
        } else if (c == 'C') {
            return 100;
        } else if (c == 'L') {
            return 50;
        } else if (c == 'X') {
            return 10;
        } else if (c == 'V') {
            return 5;
        } else {
            return 1;
        }
    }

    int romanToInt(string s) {
        int preceding, current;
        int count, integer = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if ((i + 1) < s.size()) {
                // isolate two of the numerals (or digits??)
                preceding = currentToInt(s[i]);
                current = currentToInt(s[i + 1]);

                // deciding which operation to use (add vs. subtract) before summing
                if (preceding >= current) {
                    integer += preceding;
                } else {
                    integer += current - preceding;
                    i++;
                }
            } else {
                integer += currentToInt(s[i]);
            }
        }

        return integer;
    }
};
