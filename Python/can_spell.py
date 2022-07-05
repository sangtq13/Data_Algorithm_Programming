from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # canSpell1 method: Using array to keep track of magazine
    # Time complexity: O(n)
    # Space complexity: O(k)
    def canSpell1(self, magazine, note):
        arr = [0 for _ in range(26)]
        for m in magazine:
            arr[ord(m)-ord('a')] += 1
        for n in note:
            if arr[ord(n)-ord('a')] == 0:
                return False
            arr[ord(n) - ord('a')] -= 1
        return True
    # canSpell2 method: Using dictionary to keep track of magazine
    # Time complexity: O(n)
    # Space complexity: O(size of magazine)
    def canSpell2(self, magazine, note):
        letters = defaultdict(int)
        for m in magazine:
            letters[m] += 1
        for n in note:
            if not letters[n]:
                return False
            letters[n] -= 1
        return True
print(Solution().canSpell1(['a', 'b', 'c', 'd', 'e', 'f'], 'bed'))
# True
print(Solution().canSpell2(['a', 'b', 'c', 'd', 'e', 'f'], 'bbed'))
# False
print(Solution().canSpell1(['a', 'b', 'c', 'd', 'e', 'f'], 'cat'))
# False
print(Solution().canSpell2(['a', 'b', 'c', 'd', 'e', 'f'], 'cat'))
# False
