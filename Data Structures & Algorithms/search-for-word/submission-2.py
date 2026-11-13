class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        nrows = len(board)
        ncols = len(board[0])
        def search(track, pos_x, pos_y, search_index, word):
            factors = [[-1, 0], [0, -1], [0, 1], [1, 0]]
            if pos_x < 0 or pos_x == nrows or pos_y < 0 or pos_y == ncols:
                return False
            if board[pos_x][pos_y] == word[search_index]:
                if search_index == len(word) -1:
                    return True
                track.add((pos_x, pos_y))
                search_index += 1
                valid = False
                for factor in factors:
                    if (pos_x + factor[0], pos_y + factor[1]) in track:
                        continue
                    print(pos_x + factor[0], pos_y + factor[1], word[search_index])
                    valid = search(track, pos_x + factor[0], pos_y + factor[1], search_index, word)
                    if valid:
                        return True
                track.remove((pos_x, pos_y))
            return False
        for x, rows in enumerate(board):
            for y, value in enumerate(rows):
                if (search(set(), x, y, 0, word)):
                    return True
        return False
            
                

        