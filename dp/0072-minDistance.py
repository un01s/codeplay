"""
"""
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        @cache
        def dfs(i, j):
            if i < 0: return j+1;
            if j < 0: return i+1;
            if word1[i] == word2[j]: return dfs(i-1, j-1)
            return min(dfs(i-1, j), dfs(i, j-1), dfs(i-1, j-1))+1
        return dfs(m-1, n-1) 

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        f = [[0]*(n+1) for _ in range(m+1)]
        f[0] = list(range(n+1))
        for i, x enumerate(word1):
            f[i+1][0] = i+1
            for j, y in enumerate(word2):
                f[i+1][j+1] = f[i][j] if x == y else min(f[i][j+1], f[i+1][j], f[i][j])+1
        return f(m, n)   
