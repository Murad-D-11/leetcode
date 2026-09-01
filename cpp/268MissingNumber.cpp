class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum += i;
        }

        for (int n : nums) {
            sum -= n;
        }

        return sum;
    }
};
