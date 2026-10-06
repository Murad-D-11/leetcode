class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) // <-- pretty sure there exists a separate method for this in cpp, but idc
            sum += nums[i];

        int maxSum = sum;
        int start = 0;
        int end = k;    // the end always has to be ahead of the index k - 1, so that it is able to increment the sum by that value

        while (end < nums.size()) {
            sum -= nums[start];
            start++;

            sum += nums[end];
            end++;

            maxSum = max(maxSum, sum);
        }

        return (double) maxSum / k;
    }
};
