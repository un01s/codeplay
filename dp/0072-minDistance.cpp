/*
 * leetcode 72
 * min distance
 *
 * three operations:
 * - insert a char
 * - delete a char
 * - replace a char
 *
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[501][501];
        // dp[i][j] definition
        // the distance from first i chars in word1 
        // to first j chars in word2

        int n = word1.size();
        int m = word2.size();
        // initialize
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; i <= m; j++) dp[0][j] = j;
        // dp state transfer
        // add: dp[i][j] = dp[i][j-1] + 1 
        // del: dp[i][j] = dp[i-1][j] + 1 
        // replace: dp[i][j] = dp[i-1][j-1] + 1
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
                }        
            }
        } 
        return dp[n][m];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        // initialize
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        // state transfer
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
        // dp.back().back();
    }
};

