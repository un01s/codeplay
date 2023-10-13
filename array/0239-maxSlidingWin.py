"""
leetcode 239

check another problem 155 minStack

use the zip() and -1 as the index

"""

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = collections.deque()
        res, n = [], len(nums)
        for i, j in zip(range(1-k, n+1-k), range(n)):
            # delete nums[i-1] in q
            if i > 0 and q[0] == nums[i-1]:
                q.popleft()
            # maintain a decreasing queue
            while q and q[-1] < nums[j]:
                q.pop()
            q.append(nums[j])
            # record the max in the window
            if i >= 0:
                res.append(q[0])
        return res    

