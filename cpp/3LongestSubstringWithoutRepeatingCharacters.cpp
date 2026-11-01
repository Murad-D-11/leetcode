class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int frequencies[256] = {0};

        int left = 0;
        int right = left;
        int size = s.size();

        if (size == 0) return 0;
        
        int maximum = 1;

        while (right < size && left < size) {
            frequencies[s[right]]++;

            if (frequencies[s[right]] > 1) {
                fill(begin(frequencies), end(frequencies), 0);
                
                left++;
                right = left;

                continue;
            }

            right++;
            maximum = max(maximum, right - left);
        }

        return maximum;
    }
};
