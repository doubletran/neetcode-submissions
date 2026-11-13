
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for i in nums:
            freq[i] = 1 + freq.get(i, 0)
        arr = []
        for item, freq in freq.items():
            arr.append([freq, item])
        arr.sort(reverse=True)
        res = []
        for  i in range(k):
            res.append(arr[i][1])
        return res