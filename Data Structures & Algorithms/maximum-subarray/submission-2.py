class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_sum, max_sum = 0, nums[0]
        start = 0
        end = 0
        for i in range(len(nums)):
            if nums[i] > cur_sum + nums[i]:
                start = i
                cur_sum = 0
            if cur_sum + nums[i] > max_sum:
                end = i
                max_sum = cur_sum + nums[i]
            cur_sum += nums[i]
            max_sum = max(cur_sum, max_sum)
        print(start, end)
        return max(cur_sum, max_sum)
            

            