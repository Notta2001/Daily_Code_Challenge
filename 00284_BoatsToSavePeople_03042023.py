class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        if(len(people) == 1):
            return 1
        people.sort()
        i = 0
        j = len(people) - 1
        res = 0
        while(i <= j):
            res = res + 1
            if(people[j] + people[i] <= limit):
                i = i + 1
                j = j - 1
            else:
                j = j - 1
        return res
    
# https://leetcode.com/problems/boats-to-save-people/
