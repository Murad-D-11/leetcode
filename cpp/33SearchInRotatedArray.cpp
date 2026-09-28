class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = right / 2;

        while (left <= right) {
            middle = left + ((right - left) / 2);

            if (nums[middle] >= nums[left]) {
                if (nums[middle] >= target && nums[left] <= target) {
                    right = middle;
                } else {
                    left = middle + 1;
                }
            } else {
                if (nums[middle] <= target && nums[right] >= target) {
                    left = middle;
                } else {
                    right = middle - 1;
                }
            }

            if (nums[middle] == target) return middle;
        }

        return -1;
    }
};
