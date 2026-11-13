class Solution:
    def isPalindrome(self, s: str) -> bool:
        start = 0
        end = len(s) - 1
        s = s.lower()
        while start < end:
            if s[start].isalnum():
                if s[end].isalnum():
                    if s[start] == s[end]:
                        start += 1
                        end -= 1
                        continue
                    return False
                end -= 1
                continue
            start +=1
        return True
            
            
                
        