class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> twoNums;

        for (int i = 0; i < std::size(nums); i++) {
            for (int j = 0; j < std::size(nums); j++) {
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        twoNums.push_back(i);
                        twoNums.push_back(j);
                        break;
                    }
                }
            }

            if (std::size(twoNums) == 2) {
                break;
            }
        }

        return twoNums;
    }
};
