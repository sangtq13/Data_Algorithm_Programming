class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Using other buffer to copy data
    # Time complexity: O(n)
    # Space complexity: O(n)
    def pushDominoesA(self, dominoes):
        firstR = -1
        currentIndex = 0
        n = len(dominoes)
        result = ''
        for i in range(n):
            if firstR == -1:
                if dominoes[i] == 'L':
                    result += 'L' * (i-currentIndex+1)
                    currentIndex = i+1
                elif dominoes[i] == 'R':
                    result += '.' * (i - currentIndex)
                    firstR = i
            else:
                if dominoes[i] == 'R':
                    result += 'R' * (i-firstR)
                    firstR = i
                elif dominoes[i] == 'L':
                    length = i - firstR
                    result += 'R' * (length // 2 + length%2)
                    result += '.' * (not(length%2))
                    result += 'L' * (length // 2 + length%2)
                    firstR = -1
                    currentIndex = i + 1

        if firstR != -1:
            result += (n-firstR) * 'R'
        else:
            result += dominoes[currentIndex:]

        return result
    # Using force
    # Time complexity: O(n)
    # Space complexity: O(n)
    def pushDominoesB(self, dominoes):
        n = len(dominoes)
        maxForce = n
        force = 0
        result = ''
        forces = [0 for _ in range(n)]
        for i in range(n):
            if dominoes[i] == 'R':
                force = maxForce
            elif dominoes[i] == 'L':
                force = 0
            else:
                force = max(0, force-1)
            forces[i] = force

        for i in range(n-1, -1, -1):
            if dominoes[i] == 'L':
                force = maxForce
            elif dominoes[i] == 'R':
                force = 0
            else:
                force = max(force-1, 0)
            forces[i] -= force

        for i in range(n):
            if forces[i] > 0:
                result += 'R'
            elif forces[i] == 0:
                result += '.'
            else:
                result += 'L'

        return result

s = Solution()
print(s.pushDominoesA(".L.R...LR..L.."))
print(s.pushDominoesB(".L.R...LR..L.."))
# "LL.RR.LLRRLL.."
