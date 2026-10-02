class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int answer;

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        long k = high / 2;

        // min k = min of piles; max k = max of piles; use binary search to find the value k
        while (low <= high) {
            long hours = 0;
            k = low + ((high - low) / 2);
            
            for (int i = 0; i < piles.size(); i++)
                hours += (piles[i] + k - 1) / k;

            if (hours <= h) {
                answer = k;
                high = k - 1;
            } else low = k + 1;
        }

        return answer;
    }
};
