class Solution(object):
    def findDifference(self, nums1, nums2):
        ans = [[], []]
        st1 = set(nums1)
        st2 = set(nums2)
        ans[0] = list(st1 - st2)
        ans[1] = list(st2 - st1)
        return ans

# https://leetcode.com/problems/find-the-difference-of-two-arrays/