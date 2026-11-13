class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        table = {}
        for c in s:
            if c in table:
                table[c]+= 1
            else:
                table[c] = 1
        for c in t:
            if c in table:
                table[c] -= 1
            else:
                return False
        for c in table:
            if table[c] != 0:
                return False
        return True
        
        