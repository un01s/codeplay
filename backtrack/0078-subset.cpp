/* 
 * leetcode 78 subsets
 *
 * the difference between DFS and backtracking is
 * - DFS moves to one direction till the end
 * - BP is based on DFS, but back to last level/state and continue after one end
 *
 * so the key difference is DP reseting the state and storing the path that 
 * meets the condition.
 *
 * 
 */

/*
 * recursive tree
 
     {123}
 /   1/    2/  3/
[]  {23}  {3}   N
  12/ 13/ 23/
 {3}   N    N
123/
  N

 */

class Solution {
public:
    vector<vector<int> > res;
    void bp(vector<int>& nums, vector<int>& path, int start) {
        res.push_back(path);
        for(int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]); //choose
            bp(nums, path, i+1); // next level
            path.pop_back(); // cancel the choice, backtrack
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        bp(nums, path, 0);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void bp(vector<int>& nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            bp(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        bp(nums, 0);
        return res;
    }
};
