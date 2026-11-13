class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        pos = 0
        next_pos = 1
        res = []
        while next_pos < len(intervals):
            if intervals[pos][1] >= intervals[next_pos][0]:
                intervals[pos][1] = max(intervals[pos][1], intervals[next_pos][1])
                next_pos += 1
            else:
                res.append(intervals[pos])
                pos = next_pos
                next_pos += 1
        res.append(intervals[pos])
        return res
            
        