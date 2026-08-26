class Solution {
public:
    int pivot, successor, increment;

    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 2) {
            swap(nums[0], nums[1]);
            return;
        }

        if (nums.size() > 1) {
            // locate a number that is followed by a larger number (pivot)
            for (int i = nums.size() - 2; i >= 0; i--) {
                if (nums[i + 1] > nums[i]) {
                    pivot = i;
                    break;
                }
            }

            successor = pivot + 1;

            // locate the smallest larger number that is after the pivot
            for (int j = pivot + 1; j < nums.size(); j++) {
                if (nums[successor] > nums[j] && nums[j] > nums[pivot]) {
                    successor = j;
                }
            }

            increment = (pivot == 0 && nums[pivot] >= nums[pivot + 1]) ? 0 : 1; // <--- edge case (e.g: [3, 2, 1])
            swap(nums[pivot], nums[successor]);

            // reverse the order (becomes from-smallest-to-largest)
            sort(nums.begin() + pivot + increment, nums.end());
        }
    }
};
