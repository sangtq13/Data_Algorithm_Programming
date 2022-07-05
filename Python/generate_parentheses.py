class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: less than O(2^n)
    # Space complexity: less than O(2^n)
    def __generateParenthesesHelper(self, s, left, right , result, n):
        if left == n and right == n:
            result.append(s)
            return
        if right < left:
            self.__generateParenthesesHelper(s + ')', left, right + 1, result, n)
        if left < n:
            self.__generateParenthesesHelper(s + '(', left + 1, right, result, n)

    def generateParenthesesRecursive(self, n):
        result = []
        self.__generateParenthesesHelper('(', 1, 0, result, n)
        return result

    # Time complexity: less than O(2^n)
    # Space complexity: less than O(2^n)
    def generateParentheses(self, n):
        result = []
        stack = [('(', 1, 0)]
        while stack:
            s, left, right = stack.pop()
            if left == n and right == n:
                result.append(s)
                continue
            if left < n:
                stack.append((s + '(', left + 1, right))
            if right < left:
                stack.append((s + ')', left, right + 1))
        return result

    # Time complexity: less than O(2^n)
    # Space complexity: less than O(2^n)
    def generateParenthesisA(self, N):
        if N == 0: return ['']
        ans = []
        for c in range(N):
            for left in self.generateParenthesisA(c):
                for right in self.generateParenthesisA(N - 1 - c):
                    ans.append('({}){}'.format(left, right))
        return ans

n = 3
s = Solution()
# print(s.generateParentheses(n))
# print(s.generateParenthesesRecursive(n))
print(s.generateParenthesisA(n))
print('({}){}'.format('()', ''))
