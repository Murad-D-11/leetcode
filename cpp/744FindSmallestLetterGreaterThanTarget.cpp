class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        int middle = high / 2;
        int value = letters[middle]; // we will need this to compare it to the target

        // edge-case with no other letter higher than target
        if (target >= letters[high]) return letters[0];

        while (low <= high) {
            middle = low + ((high - low) / 2); // dynamically changes the middle without varying the .size() of letters
            value = letters[middle];

            if (value <= target) low = middle + 1;
            else high = middle - 1;
        }

        return letters[low];
    }
};
