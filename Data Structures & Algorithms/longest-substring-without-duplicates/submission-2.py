class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        start = 0
        end = 0
        maxlen = 0
        hashtable = {}
        while end < len(s):
            n = s[end]
            if n in hashtable:
                print(start, end, n)
                maxlen = max(end - start, maxlen)
                start = max(start, hashtable[n]+1)
                hashtable[n] = end
                
            else:
                hashtable[n] = end
            end+= 1
        return max(end - start, maxlen)