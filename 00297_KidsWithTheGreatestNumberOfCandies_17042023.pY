class Solution:
  def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
    max_candies = max(candies)
    n = len(candies)
    res = [True]*n
    for i in range(n):
      res[i] = (candies[i] + extraCandies >= max_candies)
    return res

# https://leetcode.com/problems/kids-with-the-greatest-number-of-candies