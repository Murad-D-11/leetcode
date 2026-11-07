class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitTypeAndFreq;
        int left = 0;
        int numFruit = 0;

        int size = fruits.size();
        int maxWindow = 0;

        for (int right = 0; right < size; right++) {
            fruitTypeAndFreq[fruits[right]]++;
            numFruit++;

            while (fruitTypeAndFreq.size() > 2) {
                fruitTypeAndFreq[fruits[left]]--;
                numFruit--;

                if (fruitTypeAndFreq[fruits[left]] == 0) fruitTypeAndFreq.erase(fruits[left]);
                left++;
            }

            maxWindow = max(maxWindow, numFruit);
        }

        return maxWindow;
    }
};
