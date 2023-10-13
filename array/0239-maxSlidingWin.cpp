/*
 * leetcode 239 
 * max sliding window 
 *
 * nums, window size is k
 * return the max within the sliding window
 *
 */

//
// use deque as a monotonic queue
//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {};

        deque<int> q; 
        vector<int> res(n-k+1);
        for (int j = 0, i = 1-k; j < n; i++, j++) {
            if (i > 0 && q.front() == nums[i-1]) {
                q.pop_front();
            }
            while ( !q.empty() && q.back() < nums[j]) {
                q.pop_back();
            }
            q.push_back(nums[j]);
            //
            if (i >= 0) {
                res[i] = q.front();
            }
        }
        return res;
    }
};

//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k ==0) return {};

        deque<int> q;
        vector<int> res(n-k+1);
        // no window yet
        for (int i = 0; i < k; i++) {
            while(!q.empty() && q.back() < nums[i])
                q.pop_back();
            q.push_back(nums[i]);
        }
        res[0] = q.front();
        // window
        for (int i = k; i< n; i++) {
            if (q.front() == nums[i-k])
                q.pop_front();
            while(!q.empty() && q.back() < nums[i])
                q.pop_back();
            q.push_back(nums[i]);
            res[i-k+1] = q.front();
        }
        return res;    
    }
};


