class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = dict()
        for s in strs:
            sorted_arr = sorted(s)
            sorted_s = ""
            for ch in sorted_arr:
                sorted_s += ch 
            print(sorted_s)

            if sorted_s in anagrams:
                anagrams[sorted_s].append(s)
            else:
                anagrams[sorted_s] = [s]
        res = []
        for i in anagrams:
            res.append(anagrams[i])
        return res  