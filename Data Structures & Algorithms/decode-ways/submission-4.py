class Solution:
    def validCombo(self, char1, char2):
        combinedStr = char1 + char2
        number = int(combinedStr)
        if number >= 10 and number <=26:
            return True
        else:
            return False
    def numDecodings(self, s: str) -> int:
        size = len(s)
        way1, way2  = 1, 0
        for n in range(size):
            way = 0
            if n >= 1 and self.validCombo(s[n-1], s[n]):
                way += way2
            if s[n] != '0':
                way += way1
            way2, way1 = way1, way
        return way1
            
            
