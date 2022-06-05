class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int min = 0, max = nums.size() - 1, count = 0;
        // while (true) {
        //     for (int i = 0; i < nums.size(); i++) {
        //         if (nums[max] < nums[i]) {
        //             max = i;
        //         }
        //         if (nums[min] > nums[i]) {
        //             min = i;
        //         }
        //     }
        //     int diff = nums[max] - nums[min];
        //     if (diff == 0) {
        //         break;
        //     }
        //     count += diff;
        //     for (int i = 0; i < nums.size(); i++) {
        //         if (i != max) {
        //             nums[i] = nums[i] + diff;
        //         }
        //     }
        // }
        // return count;
        sort(nums.begin(),nums.end());
        int count = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            count += nums[i] - nums[0];
        }
        return count;
    }
    
        // public int minMoves(int[] nums) {
        // int moves = 0, min = Integer.MAX_VALUE;
        // for (int i = 0; i < nums.length; i++) {
        //     moves += nums[i];
        //     min = Math.min(min, nums[i]);
        // }
        // return moves - min * nums.length;
};