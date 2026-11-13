class Solution:
    def searchPalindrome(self, s: str, head: int, tail: int) -> int:
        if head < 0 or tail == len(s):
            return 0
        if s[head]== s[tail]:
            return 2 + self.searchPalindrome(s, head-1, tail+1)
        else:
            return 0

    def longestPalindrome(self, s: str) -> str:
        strlen = len(s)
        maxlength = 1
        string = ""
        maxstr = s[0]
        for i in range(strlen):
            if i + 2 < strlen and s[i] == s[i+2]:
                length = 3 + self.searchPalindrome(s, i-1, i+3)
                start = int(i - (length - 3)/2)
                end = int(i + 2 +(length - 3)/2)
                print(start, end)
                string = s[start:end+1]
                if len(string) > maxlength:
                    maxstr = string
                    maxlength = len(maxstr)
            if (i + 1 < strlen and s[i]== s[i+1]):
                length = 2 + self.searchPalindrome(s, i-1, i+2)
                start = int(i - (length - 2)/2)
                end = int(i + length/2)
                string = s[start:end+1]
                if len(string) > maxlength:
                    maxstr = string
                    maxlength = len(maxstr)
            print(string)

        return maxstr

