class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        totalSum = sum(nums)
        if totalSum % 2 != 0:
            return False
        sum_set = set()
        sum_set.add(0)
        for i in range(len(nums)):
            sum_set_length = len(sum_set)
            cur_sum_list = []
            for s in range(sum_set_length):
                curSum = list(sum_set)[s] +  nums[i]
                print(list(sum_set)[s], nums[i])
                if curSum == totalSum/2:
                    return True
                cur_sum_list.append(curSum)
            for x in cur_sum_list:
                sum_set.add(x)

            print(sum_set)
        return False



            

        