class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        maxi, mini = 1, 1
        all_max = nums[0]
        for num in nums:
            temp_max = max(num * maxi, num * mini, num)
            temp_min = min(num * maxi, num * mini, num)
            maxi = temp_max
            mini = temp_min
            all_max = max(maxi, all_max)
        return all_max