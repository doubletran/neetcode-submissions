class Solution:
    def rob(self, nums: List[int]) -> int:
        arr = []
        arr.append(0)
        arr.append(nums[0])
        for i in range(1, len(nums)):
            if nums[i] + arr[i-1] > arr[i]:
                arr.append(nums[i] + arr[i-1])
            else:
                arr.append(arr[i])
        print(arr)
        return arr[len(nums)]
        
            
                
        