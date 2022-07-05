from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    def __hashkey1(self, str):
        return ''.join(sorted(str))

    def __hashkey2(self, str):
        hashkey = [0] * 26
        for s in str:
            hashkey[ord(s)-ord('a')] += 1
        return tuple(hashkey)
    
    # For hashkey1 method: 
    # Time complexity: O(n*mlogm)
    # Space complexity: O(n)
    # for hashkey2 method:
    # Time complexity: O(n*m)
    # Space complexity: O(n)
    def groupAnagrams(self, strs):
        groups = defaultdict(list)
        for s in strs:
            groups[self.__hashkey2(s)].append(s)

        return groups.values()

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
#strs = ['abc', 'bcd', 'cba', 'cbd', 'efg']
s = Solution()
print(s.groupAnagrams(strs))
