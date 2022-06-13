class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def simpleCalculator(self, expression):
        ret = 0
        stack = []
        n = len(expression)
        i = 0
        operators = ['+', '-', '*', '/']
        while i < n:
            if expression[i] == '(' or expression[i] in operators:
                stack.append(expression[i])
            elif expression[i].isdigit():
                digits = ''
                for j in range(i, n):
                    if expression[j].isdigit():
                        digits += expression[j]
                    else:
                        i = j-1
                        break
                number = int(digits)
                if stack and (stack[-1] == '*' or stack [-1] == '/'):
                    operator = stack.pop()
                    leftNumber = stack.pop()
                    if (operator == '*'):
                        stack.append(leftNumber * number)
                    else:
                        stack.append(leftNumber / number)
                else:
                    stack.append(number)
            elif expression[i] == ')':
                while len(stack)>1:
                    print(stack)
                    top = stack.pop()
                    if (stack[-1] == '('):
                        stack.pop()
                        stack.append(top)
                        continue
                    else:
                        operator = stack.pop()
                        leftNumber = stack.pop()
                        if operator == '+':
                            stack.append(leftNumber + top)
                        elif operator == '-':
                            stack.append(leftNumber - top)
                        elif operator == '*':
                            stack.append(leftNumber * top)
                        elif operator == '/':
                            stack.append(leftNumber / top)
                    print(stack)
                    if stack[-1] not in operators and stack[-2] != '(':
                        break
            i += 1
        return ret

        # Time complexity: O(n)
        # Space complexity:O(k) (k depends on number of pair '()'
    def calculate(self, s):
        stack = []
        sum = 0
        sign = 1
        cur = 0
        n = len(s)
        operators = ['+', '-']
        for c in s:
            if c.isdigit():
                cur = cur * 10 + int(c)
            elif c in operators:
                sum += sign * cur
                cur = 0
                if c == '+':
                    sign = 1
                else:
                    sign = -1
            elif c == '(':
                stack.append(sum)
                stack.append(sign)
                sum = 0
                sign = 1
            elif c == ')':
                sum += cur * sign
                sum *= stack.pop()
                sum += stack.pop()
                sign = 1
                cur = 0

        return sum + (cur * sign)

    # Using recursive method:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def __eval_helper(self, expression, index):
        op = '+'
        result = 0
        while index < len(expression):
            char = expression[index]
            if char in ('+', '-'):
                op = char
            else:
                value = 0
                if char.isdigit():
                    for j in range(index, len(expression)):
                        if expression[j].isdigit():
                            value = value*10 + int(expression[j])
                        else:
                            index = j-1
                            break
                        if j == len(expression)-1:
                            index = j
                            break

                elif char == '(':
                    (value, index) = self.__eval_helper(expression, index + 1)
                elif char == ')':
                    return (result, index)
                if op == '+':
                    result += value
                if op == '-':
                    result -= value
            index += 1
        return (result, index)

    def eval(self, expression):
        return self.__eval_helper(expression, 0)[0]



s = Solution()
# print(s.simpleCalculator('(1 + (20 + (3 * 4 - (4 / (4+0) + 5 * 1 - 1))))'))
print(s.calculate("(1+(4+5+2)-3)+(6+8)"))
# print(s.calculate("(7)-(0)+(4)"))
# print(s.eval("2147483647"))
print(s.eval("(1+(4+5+2)-3)+(6+8)"))
