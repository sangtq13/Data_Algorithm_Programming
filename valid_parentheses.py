class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def validParentheses(self, s):
        p = {'[': ']', '{': '}', '(': ')'}
        stack = []
        for m in s:
            if m in p.keys():
                stack.append(m)
            else:
                if not stack or p[stack.pop()] != m:
                    return False

        return len(stack) == 0
    
    # Using replace method:
    # Time complexity: O(n^2)
    # Space complexity: O(1)
    def validParentheses(self, s):
        for i in range(len(s)):
            if len(s) != 0:
                s = s.replace('()','').replace('{}','').replace('[]','')
        return len(s) == 0      

s = Solution()
p = '(){([])}'
print(s.validParentheses(p))
