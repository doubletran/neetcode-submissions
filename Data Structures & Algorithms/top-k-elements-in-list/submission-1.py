class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequency = dict()
        for n in nums:
            if n in frequency:
                frequency[n] += 1
            else:
                frequency[n] = 1
        freq_number = dict()
        freq_list = [0]
        for n in frequency:
            if frequency[n] in freq_number:
                freq_number[frequency[n]].append(n)
            else:
                freq_number[frequency[n]] = [n]
                for i in range(0, len(freq_list)):
                    if freq_list[i] < frequency[n]:
                        freq_list.insert(i, frequency[n])
                        break
        res = []
        print(freq_list)
        for key in freq_list[:k]:
            res += freq_number[key]
            if len(res) == k:
                return res
        return res
            