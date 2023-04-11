class Solution:
    def removeStars(self, s: str) -> str:
        arr = []
        for i in range (len(s)):
            if(s[i] == '*'):
                arr.pop()
            else:
                arr.append(s[i])    
        return ''.join(arr)
    
# https://leetcode.com/problems/removing-stars-from-a-string/