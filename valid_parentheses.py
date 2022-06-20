class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def validParentheses(self, s):
        p = {'[': ']', '{': '}', '(': ')'}
        stack = []
        for m in s:
            if m in p.keys():
                stack.append(m)
            else:
                if not stack or p[stack.pop()] != m:
                    return False

        return True if not stack else False


s = Solution()
p = '(){([])}'
print(s.validParentheses(p))
