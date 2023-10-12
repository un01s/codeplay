/*
 * leetcode 704
 * binary search
 */

// 
// the search range: [l, r]
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] < target) {
                l = m+1;
            } else if (nums[m] > target) {
                r = m-1;
            } else {
                return m;
            }
        }
        return -1;
    }
};

//
// search range: [l, r)
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r-l)/2;
            if (nums[m] < target) {
                l = m+1;
            } else if (nums[m] > target) {
                r = m;
            } else {
                return m;
            }
        }
        return -1;
    }
};

