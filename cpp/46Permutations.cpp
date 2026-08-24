class Solution {
public:
    vector<vector<int>> res;

    void findPermut(vector<int>& nums, int n) {
        if (n == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = n; i < nums.size(); i++) {
            swap(nums[i], nums[n]);
            findPermut(nums, n + 1); // uses the one that had its elements swapped to branch out to the next permutation
            swap(nums[i], nums[n]); // swap back to reuse 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        findPermut(nums, 0);
        return res;
    }
};
