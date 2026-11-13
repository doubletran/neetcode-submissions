class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        maxa, maxb, maxc = 0, 0, 0
        for i in triplets:
            valid = True
            for j in range(3):
                if i[j] > target[j]:
                    valid = False
                    break
            if not valid:
                continue
            maxa = max(i[0], maxa)
            maxb = max(i[1], maxb)
            maxc = max(i[2], maxc)
        if target == [maxa, maxb, maxc]:
            return True
        else:
            return False
        