/*
 * leetcode 209
 * minimum size subarray sum
 *
 * slding window: double pointer
 *
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        // i as left pointer
        // j as right pointer
        // [i, j] forms as a sliding window
        // when the sum is greater than or equal to target
        // shrink the window by increasing i
        // widen the window by increasing j
        int n = nums.size();
        int m = INT_MAX;
        int i = 0, sum = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while(sum >= target) {
                m = min(m, j-i+1);
                sum -= nums[i++];
            }
        }
        if (m == INT_MAX) return 0;
        return m;    
    }
};

