class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 0;
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int k = right / 2;

        while (left <= right) {
            long hours = 0;
            k = left + ((right - left) / 2);

            for (int pile : piles)
                hours += (pile + k - 1) / k;

            if (hours <= h) {
                speed = k;
                right = k - 1;
            } else left = k + 1;
        }

        return speed;
    }
};
