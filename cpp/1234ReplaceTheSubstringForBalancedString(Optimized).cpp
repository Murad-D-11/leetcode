class Solution {
public:
    int balancedString(string s) {
        int ideal = s.size() / 4, minLength = s.size();

        // utilize the gimmick that chars can be interpreted as numbers to find total count of each char
        int chars[128] = {0};
        for (char c : s) {
            chars[c]++;
        }

        if (chars['Q'] == ideal && chars['W'] == ideal && chars['E'] == ideal && chars['R'] == ideal) return 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            chars[s[right]]--; // decrement a char's total count

            // using trial and error, it removes chars from a certain range until NONE of the chars are larger than the ideal
            // it then takes note of the interval length between left and right, compares it to the previous minLength, and assigns it if it is smaller than current
            while (left <= right && chars['Q'] <= ideal && chars['W'] <= ideal && chars['E'] <= ideal && chars['R'] <= ideal) {
                minLength = min(minLength, right - left + 1);

                chars[s[left]]++; // increment it back
                left++;
            }
        }

        return minLength;
    }
};
