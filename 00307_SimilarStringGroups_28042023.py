class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        groups = 0
        n = len(strs)
        vit = [False] * n
        for i in range(n):
            if vit[i]:
                continue
            else:
                groups += 1
                self.dfs(i, strs, vit)
        return groups
    
    def dfs(self, i: int, strs: List[str], vit: List[bool]) -> None:
        vit[i] = True
        for j in range(len(strs)):
            if vit[j]:
                continue
            elif self.isSimilar(strs[i], strs[j]):
                self.dfs(j, strs, vit)
    
    def isSimilar(self, str1: str, str2: str) -> bool:
        count = 0 
        for i in range(len(str1)):
            if str1[i] != str2[i]:
                count += 1
        return count == 2 or count == 0
    
# https://leetcode.com/problems/similar-string-groups/