import collections 

class Solution:
    def groupAnagrams(self, strs):
        def getKey(s):
            cnt = [0] * 26
            for c in s: cnt[ord(c) - ord('a')] += 1
            return tuple(cnt)

        d = collections.defaultdict(list)
        for s in strs:
            d[getKey(s)].append(s)
        return list(d.values())

obj = Solution()
strs = ["eat","tea","tan","ate","nat","bat"]
print(obj.groupAnagrams(strs))

# https://leetcode.com/problems/group-anagrams/
