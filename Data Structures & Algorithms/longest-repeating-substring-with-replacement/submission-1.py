class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        right = 0
        maxlen = 0
        maxfreq = 0
        freq = dict()
        while right < len(s):
            ch = s[right]
            if ch in freq:
                freq[ch] += 1
            else:
                freq[ch] = 1
            maxfreq = max(maxfreq, freq[ch])
            # check k constraint
            while right - left + 1 - maxfreq > k:
                freq[s[left]]-= 1
                left += 1
            maxlen = max(right - left + 1, maxlen)
            right += 1

        return maxlen
        

            
        