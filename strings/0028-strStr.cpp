/*
 * leetcode 28
 * find the index of the first occurence in a string
 *
 */

// brute force
// find needle in haystack
//
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};

//
// KMP
//
/*

字符串的前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串； 
字符串的后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串。

next数组存放的是当前长度下的最长相同前后缀的长度

 */

