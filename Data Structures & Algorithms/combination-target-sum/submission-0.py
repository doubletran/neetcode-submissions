class Solution:

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums = sorted(nums)
        combinations = []
        i = 0
        def dfs(start, nums, target):
            combos = []
            for i in range(start, len(nums)):
                if nums[i] == target:
                    combos.append([nums[i]])
                    break
                if nums[i] < target:
                    cur_combos = dfs(i, nums, target-nums[i])
                    for i_c, n in enumerate(cur_combos):
                        print(nums[i], target)
                        cur_combos[i_c].append(nums[i])
                        combos.append(cur_combos[i_c])
                    continue
                if nums[i] > target:
                    break
            return combos
        return dfs(0, nums, target)
            
            