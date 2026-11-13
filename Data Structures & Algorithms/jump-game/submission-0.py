class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1
        cur = goal - 1
        while cur >= 0:
            if nums[cur] >= (goal - cur):
                goal = cur
                cur = goal - 1
            else:
                cur -= 1
        if goal == 0:
            return True
        else:
            return False
        