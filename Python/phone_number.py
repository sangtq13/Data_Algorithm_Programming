lettersMaps = {
    "1": [],
    "2": ['a', 'b', 'c'],
    "3": ['d', 'e', 'f'],
    "4": ['g', 'h', 'i'],
    "5": ['j', 'k', 'l'],
    "6": ['m', 'n', 'o'],
    "7": ['p', 'q', 'r', 's'],
    "8": ['t', 'u', 'v'],
    "9": ['w', 'x', 'y', 'z'],
    "0": []
}
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def __phoneNumberHelper(self, digits, start, current, result):
        for c in lettersMaps[digits[start]]:
            newCurrent = current + c
            if start == len(digits) - 1:
                result.append(newCurrent)
            elif start < len(digits) - 1:
                self.__phoneNumberHelper(digits, start+1, newCurrent, result)

    def phoneNumber(self, digits):
        if not digits: return []
        result = []
        self.__phoneNumberHelper(digits, 0, '', result)
        return result

    def phoneNumberIterative(self, digits):
        if not digits:
            return []
        stack = [('', 0)]
        ret = []
        while stack:
            current, start = stack.pop()
            for c in lettersMaps[digits[start]]:
                newCurrent = current + c
                if start == len(digits) - 1:
                    ret.append(newCurrent)
                else:
                    stack.append((newCurrent, start+1))
        return ret

digits = "364"
print(Solution().phoneNumber(digits))
print(Solution().phoneNumberIterative(digits))

