class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int size = arr.size();
        int windowSum = 0;
        int numSubArrs = 0;

        if (size < k) return numSubArrs;

        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        for (int i = k; i < size; i++) {
            if (windowSum >= threshold * k) numSubArrs++;
            windowSum += arr[i] - arr[i - k]; 
        }

        if (windowSum >= threshold * k) numSubArrs++;

        return numSubArrs;
    }
};
