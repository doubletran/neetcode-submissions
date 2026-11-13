class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums= sorted(list(set(nums)))
        start = 0
        end = 0
        maxlen = 0
        if len(nums) == 0:
            return 0
        for i, n in enumerate(nums):
            if i == 0:
                continue
            if n - nums[i-1] == 1:
                end += 1
                print(end)
            else:
                maxlen = max(end - start + 1, maxlen)
                start = i
                end = i
        return max(end - start + 1, maxlen)
                
        