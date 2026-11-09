class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int size = nums.size();

        int maxElement;
        int indexOfMax;
        vector<int> maxElements;

        for (int right = k - 1; right < size; right++) {
            if (left == 0 || indexOfMax < left) {
                for (int i = left; i < left + k; i++) {
                    if (i == left) maxElement = nums[i];
                    if (maxElement <= nums[i]) indexOfMax = i;
                    maxElement = max(maxElement, nums[i]);
                }
            } else {
                if (maxElement <= nums[right]) indexOfMax = right;
                maxElement = max(maxElement, nums[right]);
            }

            maxElements.push_back(maxElement);
            left++;
        }

        return maxElements;
    }
};
