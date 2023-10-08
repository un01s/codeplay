/*
 * leetcode 3
 * longest substring
 *
 * use unordered_set as the hash-table
 * double-pointer
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

// this is faster but harder to understand
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int res = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            i = max(i, m[s[j]]);
            m[s[j]] = j + 1;
            res = max(res, j-i+1);
        }
        return res;
    }
};
