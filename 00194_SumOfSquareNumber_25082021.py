import math

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = int(math.sqrt(c))
        while a <= b:
            d = a*a + b*b 
            if d == c :
                print(a, "^ 2 +", b, "^ 2 =", c)
                return True
            elif d < c :
                a += 1
            else :
                b -= 1
        print("Can't find a&b")
        return False

obj = Solution()
obj.judgeSquareSum(2131)
obj.judgeSquareSum(0)
obj.judgeSquareSum(1)
obj.judgeSquareSum(322)

#https://leetcode.com/problems/sum-of-square-numbers/

