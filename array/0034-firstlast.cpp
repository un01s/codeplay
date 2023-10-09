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

