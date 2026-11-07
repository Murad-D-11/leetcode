class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        int maxWindow = 0;

        for (char replacement = 'A'; replacement <= 'Z'; replacement++) {
            int left = 0;
            int availableReplacements = k;

            for (int right = 0; right < size; right++) {
                if (s[right] != replacement) availableReplacements--;

                while (availableReplacements < 0) {
                    if (s[left] != replacement) availableReplacements++;
                    // if (availableReplacements >= 0) break;
                    
                    left++;
                }

                // if (s[left] != replacementChar) {
                //     replacementChar = s[left];
                //     availableReplacements = k;
                //     right = left;
                // }

                maxWindow = max(maxWindow, right - left + 1);
            }
        }

        return maxWindow;
    }
};
