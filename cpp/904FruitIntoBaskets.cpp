class Solution {
public:
    bool atMostTwoUniqueFruit(unordered_map<int, int> counts) {
        return counts.size() <= 2;
    }

    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> counts;

        int left = 0;
        int right = 0;
        int size = fruits.size();

        int maxSize = 0;

        counts[fruits[0]]++;

        while (right < size) {
            if (!(atMostTwoUniqueFruit(counts))) {
                counts[fruits[left]]--;
                if (counts[fruits[left]] == 0) counts.erase(fruits[left]);
                
                left++;
            } else {
                maxSize = max(maxSize, right - left + 1);
                right++;

                if (right < size) counts[fruits[right]]++;
            }
        }

        return maxSize;
    }
};
