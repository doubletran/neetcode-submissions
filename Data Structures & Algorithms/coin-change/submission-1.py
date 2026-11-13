class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        minimum = amount + 1
        dp = [amount+1] * (amount +1)
        dp[0] = 0
        for n in range(amount+1):
            for c_val in coins:
                if n - c_val >= 0:
                    dp[n] = min(dp[n], dp[n - c_val] + 1)
        if dp[amount] > amount:
            return -1
        return dp[amount]


