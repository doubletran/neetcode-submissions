class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtable = dict()
        for i, n in enumerate(nums):
            hashtable[n] = i
        for i, n in enumerate(nums):
            rem = target - n
            if rem in hashtable and hashtable[rem] != i:
                return sorted([i, hashtable[rem]])
        
            

            