class Solution:
    def search(self, nums: List[int], target: int) -> int:

        size = len(nums)
        start = 0
        end = size-1
        mid = int((end - start)/2)
        while nums[end] != target:
            print(start, end, mid)
            if (nums[mid] == target):
                return mid
            if nums[end] > nums[start]:
                if target > nums[mid]:
                    start = mid
                else:
                    end = mid
            elif nums[mid] < nums[start]:
                if target > nums[mid] and target < nums[start]:
                    start = mid
                else:
                    end = mid
            else:
                if target < nums[mid] and target > nums[end] :
                    end = mid
                else:
                    start = mid          
            mid = start + int((end-start)/2)
            if (start >= end - 1 and nums[start] != target):
                return -1
        return end



                

            
