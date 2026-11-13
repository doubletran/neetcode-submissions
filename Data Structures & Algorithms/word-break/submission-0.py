class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if len(s) == 0:
            return True
        #recursive
        for word in wordDict:
            if word in s:
                valid = True
                remaining_s = s.split(word)
                for each_s in remaining_s:
                    if not self.wordBreak(each_s, wordDict):
                        valid = False
                        break
                if not valid:
                    continue
                return True
        return False
                