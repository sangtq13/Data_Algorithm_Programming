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

s = Solution()
print(s.simpleCalculator('(1 + (20 + (3 * 4 - (4 / (4+0) + 5 * 1 - 1))))'))
