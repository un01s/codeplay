/*
 * leetcode 27
 * remove element
 * 
 *
 */

// double-pointer: fast-slow
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        left = 0
        right = n-1
        while (left <= right): 
            if (nums[left] == val):
                if (nums[right] != val):
                    nums[left], nums[right] = nums[right], nums[left]
                    left += 1
                right -= 1
            else:
                left += 1
        return left

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        slow = 0
        fast = 0
        while (fast < n): 
            if (nums[fast] != val):
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow

