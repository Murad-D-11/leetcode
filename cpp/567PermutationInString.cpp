class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int size = s2.size();

        unordered_map<int, int> validPermut;

        for (int i = 0; i < s1.size(); i++) 
            validPermut[s1[i]]++;

        for (int right = s1.size() - 1; right < size; right++) {
            unordered_map<int, int> currPermut;
            for (int j = left; j < right + 1; j++)
                currPermut[s2[j]]++;

            if (currPermut == validPermut) return true;

            left++;
        }

        return false;
    }
};
