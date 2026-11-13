class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        table = dict()
        ordered_char_list = []
        for i in range(len(s)):
            if s[i] not in table:
                table[s[i]] = [i, i]
            else:
                table[s[i]][1] = i
        i = 1
        print(table)
        range_list = [list([0,0])] * len(table)
        #simplify:
        i= 0
        print(range_list)
        for char in table:
            range_list[i]=table[char]
            i+=1
        i = 1
        while i < len(range_list):
            if range_list[i-1][1]> range_list[i][0]:
                range_list[i-1][1] = max(range_list[i-1][1], range_list[i][1])
                range_list.pop(i)
            else:
                i+=1
        print(range_list)

        return [range[1] - range[0] + 1 for range in range_list]
            
            

                
        