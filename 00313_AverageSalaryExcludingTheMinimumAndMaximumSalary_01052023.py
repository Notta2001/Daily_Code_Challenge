class Solution(object):
    def average(self, salary):
        sal_min = 1000000.0
        sal_max = 0.0
        n = len(salary)
        count = 0.0
        for i in range(0, n):
            sal_min = min(sal_min, salary[i])
            sal_max = max(sal_max, salary[i])
            count += salary[i]
        return (count - sal_min - sal_max)/(n-2)

# https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary