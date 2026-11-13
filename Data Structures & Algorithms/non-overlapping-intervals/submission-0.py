class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        print(intervals)
        prevEnd = intervals[0][1]
        remove = 0
        pos = 1
        while pos < len(intervals):
            if prevEnd > intervals[pos][0]:
                #Overlap exists
                prevEnd = min(intervals[pos][1], prevEnd)
                remove += 1
                pos+=1
            else:
                prevEnd = intervals[pos][1]
                pos+=1
        return remove


                
        