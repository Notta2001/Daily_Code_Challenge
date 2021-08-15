class Solution:
    def minNonZeroProduct(self, p):
        mod = 10**9 + 7
        n = 1 << p
        m = pow(n - 2, (n >> 1) - 1, mod) if n > 2 else 1 
        return m * (n - 1) % mod

# pow(the base, the exponent, the modulus)
obj = Solution()
for i in range(1, 60):
    print(obj.minNonZeroProduct(i))

#https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/