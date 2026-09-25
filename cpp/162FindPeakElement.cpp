class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = right / 2;

        while (left <= right) {
            middle = left + ((right - left) / 2);

            if (middle < (nums.size() - 1) && nums[middle] < nums[middle + 1]) left = middle + 1;
            else if (middle > 0 && nums[middle] < nums[middle - 1]) right = middle - 1;
            else return middle;
        }

        return middle;
    }
};
