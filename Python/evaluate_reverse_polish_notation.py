class Solution():
    def __init__(self):
        self.name = 'S->13'

    def IsNumber(self, s):
        if s[0] in ['+', '-']:
            return s[1:].isnumeric()
        return s.isnumeric()

    # Time complexity: O(n)
    # Space complexity: O(n)
    def evalRPN(self, tokens):
        stack = []
        for token in tokens:
            if self.IsNumber(token):
                stack.append(int(token))
            else:
                second_num = stack.pop()
                first_num = stack.pop()
                if token == '+':
                    stack.append(first_num + second_num)
                if token == '-':
                    stack.append(first_num - second_num)
                if token == '*':
                    stack.append(first_num * second_num)
                if token == '/':
                    # In python 2: -7/2 = -4
                    # This just works in python 3
                    stack.append(int(first_num / second_num))

        return stack[0]


tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
s = Solution()
print(s.evalRPN(tokens))
