class Solution {
public:
    bool isValid(string s) {
        int opp;
        for (int i = 0; i < s.size(); i++) {
            opp = s.size() - i - 1;

            if (s.size() % 2 != 0) return false;
            if ((i + 1) < s.size()) {
                // pairs
                if (s[i] == '(' && s[i + 1] == ')' || s[i] == '[' && s[i + 1] == ']' || s[i] == '{' && s[i + 1] == '}') {
                    i++;
                    continue;
                // symmetry
                } else if (s[i] == '(' && s[opp] == ')' || s[i] == '[' && s[opp] == ']' || s[i] == '{' && s[opp] == '}') {
                    continue;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
