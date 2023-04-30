class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        buff1 = -3
        buff2 = -3
        n = len(player1)
        score1 = 0
        score2 = 0
        for i in range(n):
            if i - buff1 <= 2:
                score1 += 2*player1[i]
            else:
                score1 += player1[i]
            if i - buff2 <= 2:
                score2 += 2*player2[i]
            else:
                score2 += player2[i]
            if player1[i] == 10:
                buff1 = i
            if player2[i] == 10:
                buff2 = i
        if score1 > score2:
            return 1
        elif score2 > score1:
            return 2
        else: 
            return 0