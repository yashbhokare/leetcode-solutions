class Solution {
public:
    int result = INT_MIN;

    // Standard Kadane's algorithm.
    int getMaxKadane(vector<int>& nums) {
        int maxKadane = INT_MIN, currentMaxSum = 0;
        for (int& num : nums) {
            currentMaxSum = max(currentMaxSum + num, num);
            maxKadane = max(maxKadane, currentMaxSum);
        }
        return maxKadane;
    }
    void updateResult(vector<int>& nums, int k) {
        int kadaneSum = getMaxKadane(nums);

        // If max possible sum of any subarray of nums is <=k
        // use that result to compare with gobal maxium result and return
        if (kadaneSum <= k) {
            result = max(result, kadaneSum);
            return;
        }
        int sum = 0;

        // Container to store sorted prefix sums.
        set<int> sortedSum;
        set<int>::iterator it;

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.insert(0);
        for (int& num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            it = sortedSum.lower_bound(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum result.
            if (it != sortedSum.end())
                result = max(result, sum - *it);

            // Insert the current running sum to the prefix sums container.
            sortedSum.insert(sum);
        }
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
            // Stores the 1D representation of the matrix row wise.
            vector<int> rowSum(matrix[0].size());
            for (int i = 0; i < matrix.size(); i++) {
                // Initialize the 1D representation with 0s.
                fill(rowSum.begin(), rowSum.end(), 0);

                // We convert the matrix between rows i..row inclusive to 1D array
                for (int row = i; row < matrix.size(); row++) {
                    // Add the current row to the previous row.
                    // This converts the matrix between i..j to 1D array
                    for (int col = 0; col < matrix[0].size(); col++)
                        rowSum[col] += matrix[row][col];

                    // Run the 1D algorithm for `rowSum`
                    updateResult(rowSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        return result;
    }
};