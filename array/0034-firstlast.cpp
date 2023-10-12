/*
 * leetcode 34
 * find first and last position of element in sorted array
 *
 * sorted -> binary search
 *
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n-1;
        int m = 0;
        vector<int> res(2, -1);
        bool found = false;

        // binary search
        while (i <= j) {
            m = i + (j-i)/2;
            if (nums[m] == target) {
                found = true;
                break;
            } else if (nums[m] > target) {
                j = m-1;
            } else {
                i = m+1;
            }
        }
        if (!found) {
            return res;
        }
        i = m;
        while((i-1) >= 0 && (nums[m]==nums[i-1])) {
            i--;
        }
        res[0] = i;
        j = m;
        while((j+1) < n && (nums[m]==nums[j+1])) {
            j++;
        }
        res[1] = j;
        return res;    
    }
};

//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1; // [i, j]
        while (i <= j) {
            int m = i + (j-i)/2;
            if (nums[m] < target) {
                i = m+1; // [m+1, j]
            } else {
                j = m-1; // [i, m-1]
            }
        }
        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = search(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = search(nums, target+1) -1;
        return {start, end};
    }
};

