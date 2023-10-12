"""
leetcode 287

use set in python
"""

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        hmap = set()
        for num in nums:
            if num in hmap: return num
            hmap.add(num)
        return -1

