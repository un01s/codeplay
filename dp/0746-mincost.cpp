/*
 * leetcode 746
 *
 * DP
 *
 */

// easier to understand
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] += min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};

// compact
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i = 2; i < n; i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }    
        return min(cost[n-1], cost[n-2]);
    }
};

