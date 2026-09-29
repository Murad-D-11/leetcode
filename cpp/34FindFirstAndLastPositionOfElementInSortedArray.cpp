class Solution {
public:
    int binarySearchRecursive(vector<int>& nums, int target, bool leftBias) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = right / 2;

        int index = -1;

        while (left <= right) {
            middle = left + ((right - left) / 2);

            if (nums[middle] < target) left = middle + 1;
            else if (nums[middle] > target) right = middle - 1;
            else {
                index = middle;
                if (leftBias) right = middle - 1;
                else left = middle + 1;
            }
        }

        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearchRecursive(nums, target, true);
        int rightIndex = binarySearchRecursive(nums, target, false);
        
        return {leftIndex, rightIndex};
    }
};
