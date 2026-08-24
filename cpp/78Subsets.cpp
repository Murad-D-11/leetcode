class Solution {
public:
    vector<vector<int>> allSubsets;
    vector<int> subset;

    void findSubset(vector<int>& nums, int n) {
        if (n == nums.size()) {
            allSubsets.push_back(subset);
            return;
        }

        // include
        subset.push_back(nums[n]);
        findSubset(nums, n + 1);

        // exclude
        subset.pop_back();
        findSubset(nums, n + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        findSubset(nums, 0);
        return allSubsets;
    }
};
