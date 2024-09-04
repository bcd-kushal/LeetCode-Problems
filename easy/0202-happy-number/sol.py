class Solution:
    @staticmethod
    def sum_of_squares(n: int) -> int:
        if n==0 :
            return 0
        return (n%10)**2 + Solution.sum_of_squares(n//10)

    def isHappy(self, n: int) -> bool:
        if n <= 3:
            return False

        visited_nums = set()
        sq = self.sum_of_squares(n)

        while sq != 1 and sq not in visited_nums:
            visited_nums.add(sq)
            sq = self.sum_of_squares(sq)

        return True if sq == 1 else False
        