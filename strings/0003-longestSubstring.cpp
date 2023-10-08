/*
 * leetcode 3
 * longest substring
 *
 * use unordered_set as the hash-table
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int len = s.size();
        int window = 0;
        unordered_set<char> uset;
        for (int l = 0, r = 0; r < len; r++) {
            while (l < r && uset.count(s[r])) {
                // s[r] already in uset
                // so [l, r] has duplicates
                // now move the left pointet so that there is no duplicates
                // in the window [l, r]
                uset.erase(s[l]);
                l++;
                window--;
            }
            uset.insert(s[r]);
            window++;
            res = max(res, window);
        }    
        return res;
    }
};

