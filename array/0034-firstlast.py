"""
leetcode 34
binary search

"""

def lower_bound(nums: List[int], target: int) -> int:
    # [left, right]
    left, right = 0, len(nums) - 1
    while left <= right:
        # loop invariant
        # nums[left-1] < target
        # nums[right+1] >= target
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1  # --> [mid+1, right]
        else:
            right = mid - 1  # --> [left, mid-1]
    return left

def lower_bound2(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums)  # range: [left, right)
    while left < right:  # 
        # loop invariants:
        # nums[left-1] < target
        # nums[right] >= target
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1  # range --> [mid+1, right)
        else:
            right = mid  # range --> [left, mid)
    return left  # or right

#
# (left, right)
#
def lower_bound3(nums: List[int], target: int) -> int:
    left, right = -1, len(nums)  # range: (left, right)
    while left + 1 < right:  # 
        mid = (left + right) // 2
        # loop invariants:
        # nums[left] < target
        # nums[right] >= target
        if nums[mid] < target:
            left = mid  # range --> (mid, right)
        else:
            right = mid  # range --> (left, mid)
    return right  # or left+1

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start = lower_bound(nums, target)  # either one above
        if start == len(nums) or nums[start] != target:
            return [-1, -1]
        # if start exists, then end exists too.
        end = lower_bound(nums, target + 1) - 1
        return [start, end]

