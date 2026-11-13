class Solution:
    def findMin(self, nums: List[int]) -> int:
        size = len(nums)
        
        if nums[0] < nums[size-1]:
            return nums[0]
        i = int(size/2)
        start = 0
        end = size - 1
        while i >= 0 and i < size:
            if end - start <= 1:
                return min(nums[end], nums[start])
            if nums[i] < nums[start]:
                end = i
                i = int(i - (end - start)/2)
            else:
                start = i
                i = int(i + (end - start)/2)


        

            
        