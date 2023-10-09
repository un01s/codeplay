/*
 * leetcode 53
 * maximum subarray
 * 
 * the similar idea between 53 and 124
 *
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); 
        // dp[i] = the max sum of consecutive sub array 
        // ending with nums[i]
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (dp[i-1] > 0) {
                dp[i] = dp[i-1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
        }
        int res = dp[0];
        for (int i = 1; i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

