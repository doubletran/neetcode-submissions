class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        prefixes = [1] * (size+1)
        prefixes[0] = 1
        suffixes = [1] * (size+1)
        suffixes[0] = 1
        for i in range(1, size+1):
            prefixes[i] = prefixes[i-1] * nums[i-1]
            suffixes[i] = suffixes[i-1] * nums[size-i]
        print(prefixes, suffixes)
        product = [0] * len(nums)
        for i in range(size):
            product[i] = prefixes[i] * suffixes[size-1-i]
        return product

        
            
        