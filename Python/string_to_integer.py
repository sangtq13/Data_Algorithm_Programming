class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def StringToInteger(self, s):
        sign = 1
        check_digit = False
        check_sign = False
        num = 0
        INT_MAX = pow(2, 31) - 1
        INT_MIN = -pow(2, 31)

        for m in s:
            if m == ' ' and not check_digit and not check_sign:
                continue
            if not m.isdigit():
                if m not in ['-', '+'] or check_sign or check_digit:
                    break
            else:
                check_digit = True
                num = num * 10 + int(m)
            if m in ['-', '+']:
                if m == '-':
                    sign = -1
                check_sign = True
        num = sign * num
        if num < INT_MIN:
            return INT_MIN
        if num > INT_MAX:
            return INT_MAX

        return num

print(Solution().StringToInteger(' + 123'))
