class Solution(object):
    def arraySign(self, nums):
        mul = 1
        for num in nums:
            if num == 0:
                return 0
            elif num < 0: 
                mul *= -1
        return mul

# https://leetcode.com/problems/sign-of-the-product-of-an-array