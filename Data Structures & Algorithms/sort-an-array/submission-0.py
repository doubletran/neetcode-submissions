class Solution:
    def merge(self, left_arr, right_arr):
        arr= []
        l = 0
        r = 0
        while l < len(left_arr) and r < len(right_arr):
            if left_arr[l] < right_arr[r]:
                arr.append(left_arr[l])
                l += 1
            else:
                arr.append(right_arr[r])
                r +=1
        while l < len(left_arr):
            arr.append(left_arr[l])
            l += 1
        while r < len(right_arr):
            arr.append(right_arr[r])
            r += 1
        return arr
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) == 1:
            return nums
        end = len(nums)
        mid = int(end/2)
        left_arr = self.sortArray(nums[0:mid])
        right_arr = self.sortArray(nums[mid:end])
        return self.merge(left_arr, right_arr)  
        
        