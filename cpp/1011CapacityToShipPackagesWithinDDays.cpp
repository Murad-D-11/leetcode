class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int actualCapacity = 0;

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int capacity = high / 2;

        while (low <= high) {
            int accumDays = 1;
            int totalWeight = 0;
            capacity = low + ((high - low) / 2);

            for (int weight : weights) {
                if ((totalWeight + weight) > capacity) {
                    accumDays++;
                    totalWeight = weight;
                } else totalWeight += weight;
            }               
            
            if (accumDays <= days) {
                actualCapacity = capacity;
                high = capacity - 1;
            } else low = capacity + 1;
        }

        return actualCapacity;
    }
};
