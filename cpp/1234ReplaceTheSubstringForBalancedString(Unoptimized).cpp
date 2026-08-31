class Solution {
public:
    int balancedString(string s) {
        int excessQ, excessW, excessE, excessR, ideal;
        ideal = s.size() / 4;

        // find excess, otherwise zero
        excessQ = max(0, static_cast<int>(count(s.begin(), s.end(), 'Q') - ideal));
        excessW = max(0, static_cast<int>(count(s.begin(), s.end(), 'W') - ideal));
        excessE = max(0, static_cast<int>(count(s.begin(), s.end(), 'E') - ideal));
        excessR = max(0, static_cast<int>(count(s.begin(), s.end(), 'R') - ideal));

        if (excessQ == 0 && excessW == 0 && excessE == 0 && excessR == 0) {
            return 0;
        }

        // find the substring that hovers over the excess amount of that(those) character(s)
        for (int minLength = excessQ + excessW + excessE + excessR; minLength <= s.size(); minLength++) {
            for (int shift = 0; shift + minLength <= s.size(); shift++) {
                // count the chars within the sub string
                int subQ = 0, subW = 0, subE = 0, subR = 0;
                for (int i = shift; i < minLength + shift; i++) {
                    if (s[i] == 'Q') subQ++;
                    else if (s[i] == 'W') subW++;
                    else if (s[i] == 'E') subE++;
                    else if (s[i] == 'R') subR++;
                }

                if (subQ >= excessQ && subW >= excessW && subE >= excessE && subR >= excessR) return minLength;
            }
        }

        // if everything needs to be replaced
        return s.size();
    }
};
