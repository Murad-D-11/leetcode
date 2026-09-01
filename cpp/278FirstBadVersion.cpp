// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int middle = low + ((high - low) / 2);

        while (low < high) {
            middle = low + ((high - low) / 2);

            if (isBadVersion(middle)) high = middle;
            else low = middle + 1;
        }

        return (!isBadVersion(middle)) ? middle + 1 : middle;
    }
};
