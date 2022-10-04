from collections import defaultdict
import math
MOD = 1e9 + 7
class Solution():
    def __init__(self):
        self.name = 'S->13'

    def __DFS(self, graph, parent, cur, G, B):
        leaf = True
        for neighbor in graph[cur]:
            if neighbor == parent:
                continue
            leaf = False
            self.__DFS(graph, cur, neighbor, G, B)
        if leaf:
            G[cur] = 0
            B[cur] = 1
            return
        for neighbor in graph[cur]:
            if neighbor == parent:
                continue
            B[cur] *= G[neighbor]
            G[cur] *= (2 * G[neighbor] + B[neighbor])
            B[cur] %= MOD
            G[cur] %= MOD
        G[cur] = (G[cur] + MOD - B[cur]) % MOD

    # Recursive solution
    # Time complexity: O(n)
    # Space complexity: O(n)
    def KingdomDivision(self, n, roads):
        G = [1 for _ in range(n+2)]
        B = [1 for _ in range(n+2)]
        graph = defaultdict(list)
        for road in roads:
            graph[road[0]].append(road[1])
            graph[road[1]].append(road[0])

        self.__DFS(graph, 0, 1, G, B)

        return math.floor((2 * G[1]) % MOD)

roads = [[1, 2], [1, 3], [3, 4], [3, 5]]
n = len(roads)
n = len(roads)
print(Solution().KingdomDivision(n, roads))

