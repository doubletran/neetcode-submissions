class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0] * n
        step1 = 1
        step2 = 0
        step = 0
        for i in range(0, n):
            step = step1 + step2
            step1, step2 = step, step1
        return step