class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // find the shortest word in array of strings
        std::string shortestWord;
        for (int i = 0; i < std::size(strs); i++) {
            if (i > 0) {
                if (std::size(shortestWord) < std::size(strs[i])) {
                    shortestWord = strs[i];
                }
            } else {
                shortestWord = strs[i];
            }
        }

        // find common letters
        int maxLetters = std::size(shortestWord);
        char currentLetter;
        std::string commonPrefix;
        for (int i = 0; i < maxLetters; i++) {
            for (int j = 0; j < std::size(strs); j++) {
                if (j == 0) currentLetter = strs[j][i];
                
                if (currentLetter != strs[j][i]) {
                    return commonPrefix;
                }
            }

            commonPrefix += currentLetter;
        }

        return commonPrefix;
    }
};
