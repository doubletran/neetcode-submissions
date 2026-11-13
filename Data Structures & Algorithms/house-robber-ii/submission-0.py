class Solution:

    def rob(self, nums: List[int]) -> int:
        robhead1, robhead2 = 0, nums[0]
        robnohead1, robnohead2 = 0, 0
        tail = len(nums) - 1
        for i in range(1, tail):
            #include head
            temp = max(nums[i] + robhead1, robhead2)
            robhead1= robhead2
            robhead2 = temp

            #skip head
            temp = max(nums[i] + robnohead1, robnohead2)
            robnohead1 = robnohead2
            robnohead2 = temp
        robnohead2 = max(nums[tail] + robnohead1, robnohead2)
        return max(robhead2, robnohead2)




        