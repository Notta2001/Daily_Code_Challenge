from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i + 1
            r = len(nums) - 1
            while l < r:
                if nums[i] + nums[l] + nums[r] == 0 :
                    res.append([nums[i], nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l-1] and l < r:
                        l += 1
                elif nums[i] + nums[l] + nums[r] < 0:
                    l += 1
                else :
                    r -= 1
        return res

nums = [-1, 0, 1, 2, -1, -4]
obj = Solution()
print(obj.threeSum(nums))
# https://leetcode.com/problems/3sum/