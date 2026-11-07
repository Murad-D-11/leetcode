class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int size = nums.size();
        int maxWindow = 0;

        int availableZeroes = k;

        for (int right = 0; right < size; right++) {
            if (nums[right] == 0) {
                availableZeroes--;
            }

            while (availableZeroes < 0 && nums[right] == 0) {
                if (nums[left] == 0) availableZeroes++;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return maxWindow;
    }
};
