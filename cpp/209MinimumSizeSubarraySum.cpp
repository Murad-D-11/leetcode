class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int windowSum = 0;

        // something specific for this problem that is not in classic Sliding Window alg
        int left = 0;
        int minimum = size + 1;

        for (int i = 0; i < size; i++) {
            windowSum += nums[i];

            while (windowSum >= target) {
                minimum = min(minimum, i - left + 1);
                windowSum -= nums[left];
                left++;
            }
        }

        return minimum <= size ? minimum : 0;
    }
};
