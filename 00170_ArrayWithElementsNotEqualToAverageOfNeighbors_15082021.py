class Solution:
    def rearrangeArray(self, nums):
        n = len(nums)
        i = 1
        while i < n - 1:
            s = nums[i-1] + nums[i+1]
            if s % 2 == 0 and nums[i] == s / 2:
                nums[i], nums[i+1] = nums[i+1], nums[i]
                if i > 1:
                    i -= 1
            else:
                i += 1
        return nums

nums = [1, 2, 3, 4, 5]
print(nums)
obj = Solution()
print(obj.rearrangeArray(nums))

#https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/