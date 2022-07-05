class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(n)
    def absolutePath(self, path):
        folders = path.split('/')
        stack = []
        for f in folders:
            if f == '..':
                stack.pop()
            elif f == '.':
                continue
            else:
                stack.append(f)
        return '/'.join(stack)

path = '/users/tech/docs/.././desk/../'
# /users/tech/
print(Solution().absolutePath(path))
