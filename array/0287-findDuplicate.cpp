/*
 * leetcode 287
 * find duplicate
 *
 * there is only one repeated number in nums, return this repeated number.
 * 
 * use unordered_map as the hash table
 *
 * use unordered_set as the hash
 * 
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1) {
                return nums[i];
            }
        }
        return -1;    
    }
};

//
// unordered_map
//
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (int n : nums) {
            if (mp[n]) return n;
            mp[n] = true;
        }
        return -1;    
    }
};


//
// use the functions of unordered_set
// find()
// insert()
//
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                return nums[i];
            }
            seen.insert(nums[i]);
        }    
        return -1;
    }
};
