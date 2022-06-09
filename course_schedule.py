from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.name = 'S->13'
    
    # Using recursive DFS
    # Time complexity: O(n^2)
    # Space complexity: O(n)
    def __hasCycle(self, graph, course, seen, cache):
        if course in cache:
            return cache[course]
        if course in seen:
            return True
        seen.add(course)
        ret = False
        for neighbors in graph[course]:
            if self.__hasCycle(graph, neighbors, seen, cache):
                ret = True
                break
        cache[course] = ret
        seen.remove(course)
        return ret

    def courseSchedule(self, numCourses, prerequisites):
        graph = defaultdict(list)
        for p in prerequisites:
            graph[p[0]].append(p[1])
        state = defaultdict(bool)
        for course in range(numCourses):
            # if self.__hasCycle(graph, course, set(), {}):
            if self.__hasCycleIterative(graph, course, state):
                return False
        return True

    # Using stack
    # Time complexity: O(n^2)
    # Space complexity: O(n)
    def __hasCycleIterative(self, graph, course, state):
        stack = [course]
        seen = []
        while stack:
            course = stack[-1]
            if state[course]:
                stack.pop()
                if seen and course == seen[-1]:
                    seen.pop()
                continue
            if course in seen and course != seen[-1]:
                return True

            ret = True
            for neighbor in graph[course]:
                if neighbor == course:
                    return True
                if not state[neighbor] and neighbor != course:
                    ret = False
                    stack.append(neighbor)
            if ret:
                state[course] = True
            else:
                seen.append(course)
        return False
s = Solution()
# prerequisites = [[1,4],[2,4],[3,1],[3,2]]
# print(s.courseSchedule(4, prerequisites))
# print(s.courseScheduleIterative(4, prerequisites))
prerequisites = [[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]
# prerequisites = [[0, 1]]
print(s.courseSchedule(20, prerequisites))
# print(s.courseScheduleIterative(7, prerequisites))
