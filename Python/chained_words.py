from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # DFS method using recursive and hashmap
    # Time complexity: O(n)
    # Space complexity: O(n)
    def __chainedWordsHelper(self, graph, start, current, length, visited):
        if length == 1:
            return current[-1] == start[0]
        visited.add(current)
        for node in graph[current[-1]]:
            if node not in visited and self.__chainedWordsHelper(graph, start, node, length-1, visited):
                return True
        visited.remove(current)
        return False

    def chainedWords(self, words):
        length = len(words)
        graph = defaultdict(list)
        for w in words:
            graph[w[0]].append(w)

        return self.__chainedWordsHelper(graph, words[0], words[0], length, set())

    # Iterative method using stack
    # Time complexity: O(n)
    # Space complexity: O(n)
    def chainedWordsIterative(self, words):
        size = len(words)
        graph = defaultdict(list)
        for w in words:
            graph[w[0]].append(w)
        visited = set()
        stack = [(words[0], 1)]
        while stack:
            node, length = stack.pop()
            if length == size:
                return node[-1] == words[0][0]
            visited.add(node)
            check = True
            for neighbor in graph[node[-1]]:
                if neighbor not in visited:
                    check = False
                    stack.append((neighbor, length+1))
            if check:
                return False

        return False

print(Solution().chainedWords(['apple', 'eggs', 'snack', 'karat', 'tuna', 'ab', 'bc', 'ca']))
print(Solution().chainedWordsIterative(['apple', 'eggs', 'snack', 'karat', 'tuna', 'ab', 'bc', 'ca']))
# True

print(Solution().chainedWords(['apple', 'eggs', 'snack', 'karat', 'tunax']))
print(Solution().chainedWordsIterative(['apple', 'eggs', 'snack', 'karat', 'tunax']))
# False
