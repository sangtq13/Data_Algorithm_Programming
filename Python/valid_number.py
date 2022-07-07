BEGIN = 0
SIGN1 = 1
DIGIT1 = 2
DOT1 = 3
DOT2 = 4
DIGIT2 = 5
E = 6
SIGN2 = 7
DIGIT3 = 8

STATE_VALIDATOR = {
    BEGIN: lambda x: True,
    SIGN1: lambda x: x in ['-', '+'],
    DIGIT1: lambda x: x.isdigit(),
    DOT1: lambda x: x == '.',
    DOT2: lambda x: x == '.',
    DIGIT2: lambda x: x.isdigit(),
    E: lambda x: x in ['E', 'e'],
    SIGN2: lambda x: x in ['-', '+'],
    DIGIT3: lambda x: x.isdigit()
}


NEXT_STATES_MAP = {
    BEGIN: [DOT1, SIGN1, DIGIT1],
    SIGN1: [DOT1, DIGIT1, DIGIT2, DIGIT3],
    DIGIT1: [DOT2, DIGIT1, E],
    DOT1: [DIGIT2],
    DOT2: [DIGIT2, E],
    DIGIT2: [E, DIGIT2],
    E: [SIGN2, DIGIT3],
    SIGN2: [DIGIT3],
    DIGIT3: [DIGIT3],
}

class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(k)
    def validNumber(self, s):
        currentState = BEGIN

        for c in s:
            for nextState in NEXT_STATES_MAP[currentState]:
                found = False
                if STATE_VALIDATOR[nextState](c):
                    found = True
                    currentState = nextState
                    break
            if not found:
                return False

        return currentState in [DOT2, DIGIT1, DIGIT2, DIGIT3]

    def validNumbers(self, strs):
        for s in strs:
            if (self.validNumber(s)):
                print(s, 'Yes')
            else:
                print(s, 'No')

s = Solution()
str = ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
s.validNumbers(str)
# False
str = ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", "-1.", "-1.", "46.e3"]
s.validNumbers(str)
# Yes

