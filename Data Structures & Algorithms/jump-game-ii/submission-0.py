class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        minjump = [size-1] * size
        minjump[0] = 0
        for i in range(1, size):
            for j in range(0, i):
                #if i is reachable from j
                if nums[j] >= i - j:
                    minjump[i]= min(minjump[i], minjump[j])
            minjump[i] += 1
        return minjump[size-1]
            
        