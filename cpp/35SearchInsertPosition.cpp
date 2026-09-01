class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int middle = high / 2;
        int value = nums[middle];

        while (low <= high) {
            middle = low + ((high - low) / 2);
            value = nums[middle];

            if (value < target) low = middle + 1;
            else if (value > target) high = middle - 1;
            else return middle;
        }

        if (target > value) return middle + 1;
        else return middle;
    }
};
