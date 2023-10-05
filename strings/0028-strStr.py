"""
leetcode 28 strStr
find a string needle in another string haystack
"""

# 
# brute force
#
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        L, n = len(needle), len(haystack)

        for start in range(n - L + 1):
            if haystack[start:start + L] == needle:
                return start
        return -1

#
# use the find function
#
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
