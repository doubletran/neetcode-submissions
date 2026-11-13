class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if len(prerequisites) == 0:
            return True
        adjlist = [[] for _ in range(numCourses)] 
        stack = []
        for course, prereq in prerequisites:
            adjlist[course].append(prereq)
            

        visited = set()
        visiting = set()
        def dfs(node):
            if node in visited:
                return True
            if node in visiting:
                return False
            visiting.add(node)
            for neighbor in adjlist[node]:
                if dfs(neighbor):
                    continue
                return False
            visited.add(node)
            visiting.remove(node)
            return True
        for course, prereq in prerequisites:
            if dfs(course):
                continue
            return False
        return True

