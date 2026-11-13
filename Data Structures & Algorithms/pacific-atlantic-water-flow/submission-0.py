
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        nrow = len(heights)
        ncol = len(heights[0])
        adjlist = [[] for _ in range(nrow * ncol)]
        def addEdge(r,c, r_adj, c_adj):
            if r_adj >= 0 and r_adj < nrow and c_adj >= 0 and c_adj < ncol and heights[r_adj][c_adj] >= heights[r][c]:
                adjlist[r*ncol + c].append(r_adj *ncol + c_adj)
            
        for r in range(nrow):
            for c in range(ncol):
                addEdge(r, c, r-1, c)
                addEdge(r, c, r+1, c)
                addEdge(r, c, r, c-1)
                addEdge(r, c, r, c+1)
        def bfs(q):
            visited = set()
            while len(q) > 0:
                curr = q.popleft()
                if curr in visited:
                    continue
                visited.add(curr)
                for neighbor in adjlist[curr]:
                    q.append(neighbor)
            return visited
        #add top left edges
        q = deque()
        for c in range(ncol):
            q.append(c)
        for r in range(1, nrow):
            q.append(r*ncol)
        pacific = bfs(q)
        print(pacific)
        #add top left edges
        q = deque()
        for c in range(ncol):
            q.append((nrow-1) * ncol + c)
        for r in range(0, nrow-1):
            q.append(r*ncol + (ncol-1))
        atlantic = bfs(q)
        print(atlantic)
        result = atlantic.intersection(pacific)
        return [[int(pos/ncol), pos % ncol] for pos in list(result)]
            

                