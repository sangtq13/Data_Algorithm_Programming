from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

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

        for course in range(numCourses):
            if self.__hasCycle(graph, course, set(), {}):
                return False
        return True
    
    def courseScheduleIterative(self, numCourses, prerequisites):
        

s = Solution()
prerequisites = [[0,1], [1,2], [2,3], [4,5], [5,6]]
print(s.courseSchedule(6, prerequisites))
prerequisites = [[0,1], [1,2], [2,3], [4,5], [5,6], [3,0]]
print(s.courseSchedule(7, prerequisites))
