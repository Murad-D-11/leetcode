class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int size = s.size();
        int minWindow = size + 1;
        string substring = "";

        unordered_map<int, int> target;
        unordered_map<int, int> current;
        int match = 0;

        for (int i = 0; i < t.size(); i++)
            target[t[i]]++;

        int targetCount = target.size();
        int bestLeft = size;

        for (int right = 0; right < size; right++) {
            if (target.contains(s[right])) {
                current[s[right]]++;
                if (current[s[right]] == target[s[right]]) match++;
            }
            
            while (match == targetCount) {
                int currentSize = right - left + 1;

                if (minWindow > currentSize) {
                    bestLeft = left;
                }
                minWindow = min(minWindow, currentSize);

                if (target.contains(s[left])) {
                    current[s[left]]--;
                    if (target[s[left]] > current[s[left]]) match--;
                }

                left++;
            }
        }

        substring = s.substr(bestLeft, minWindow);
        return substring;
    }
};
