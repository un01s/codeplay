"""
leetcode 3 longest substring
double-pointer: left and right
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic, res, i = {}, 0, -1
        for j in range(len(s)):
            if s[j] in dic:
                i = max(dic[s[j]], i) # update left pointer i
            dic[s[j]] = j # record in the dictionary as hash-table
            res = max(res, j - i) # update the result
        return res

