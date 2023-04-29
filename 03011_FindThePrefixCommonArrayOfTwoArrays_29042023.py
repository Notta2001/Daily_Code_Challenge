class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        check = [0]*(n+1)
        res = [0]*(n)
        for i in range(n):
            check[A[i]] += 1
            check[B[i]] += 1
            for j in range(1, n+1):
                if(check[j] == 2):
                    res[i] += 1
        return res
                