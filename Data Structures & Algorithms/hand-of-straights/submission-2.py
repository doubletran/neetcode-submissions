class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        totalSize = len(hand)
        if totalSize % groupSize != 0:
            return False
        
        hashmap = [0] * (max(hand) + 1)
        for i in hand:
            hashmap[i] += 1
        for i in range(len(hashmap)):
            if hashmap[i] > 0:
                print(i)
                for j in range(groupSize-1, -1, -1):
                    if i + j <= len(hashmap)-1:
                        hashmap[i + j] -= hashmap[i]
                    else:
                        return False
        print(hashmap)
        hashset = set(hashmap)
        if list(hashset) != [0]:
            return False
        return True
        

